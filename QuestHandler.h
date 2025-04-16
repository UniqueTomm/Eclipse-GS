#pragma once
#include "framework.h"

namespace Quests
{
	UFortQuestItemDefinition* GetQuest(AFortPlayerControllerAthena* PlayerController, FDataTableRowHandle ObjectiveStat)
	{
		UFortQuestManager* QuestManager = PlayerController->GetQuestManager(ESubGame::Athena);
		TArray<UFortQuestItem*> CurrentQuests;
		QuestManager->GetCurrentQuests(&CurrentQuests);

		if (CurrentQuests.IsValid())
		{
			for (int i = 0; i < CurrentQuests.Num(); i++)
			{
				UFortQuestItem* CurrentQuest = CurrentQuests[i];
				if (!CurrentQuest)
					continue;

				UFortQuestItemDefinition* QuestDefinition = CurrentQuest->GetQuestDefinitionBP();
				if (!QuestDefinition)
					continue;

				for (int i = 0; i < QuestDefinition->Objectives.Num(); i++)
				{
					FFortMcpQuestObjectiveInfo ObjectiveInfo = QuestDefinition->Objectives[i];
					FDataTableRowHandle ObjectStatHandle = ObjectiveInfo.ObjectiveStatHandle;
					UDataTable* DataTable = ObjectStatHandle.DataTable;
					if (!DataTable)
						continue;

					auto& RowMap = DataTable->RowMap;
					FFortQuestObjectiveStatTableRow* Row = nullptr;

					if (RowMap.Num() <= 0)
						continue;

					for (int i = 0; i < RowMap.Num(); ++i)
					{
						auto& Pair = RowMap[i];
						if (Pair.Key().ToString() == ObjectiveStat.RowName.ToString())
						{
							LogInfo("Sigma? ({}) : ({})", ObjectiveStat.RowName.ToString(), Pair.Key().ToString());
							Row = reinterpret_cast<FFortQuestObjectiveStatTableRow*>(Pair.Second);
							break;
						}
					}

					if (Row)
						return QuestDefinition;
				}
			}
		}
		else
			LogWarning("Quests::GetQuest: CurrentQuests invalid, lol.");


		LogWarning("Quests::GetQuest: Could not get quest.");
		return nullptr;
	}

	void ProgressQuest(AFortPlayerControllerAthena* PlayerController, FName BackendName, UFortQuestItemDefinition* QuestItemDefinition, int Count = 1, bool bActive = true)
	{
		UFortQuestManager* QuestManager = PlayerController->GetQuestManager(ESubGame::Athena);
		UFortQuestItem* QuestItem = QuestManager->GetQuestWithDefinition(QuestItemDefinition);
		if (QuestItem)
		{
			TArray<UFortQuestObjectiveInfo*> Objectives = QuestItem->Objectives;
			for (int i = 0; i < Objectives.Num(); i++)
			{
				UFortQuestObjectiveInfo* Objective = Objectives[i];
				if (!Objective)
					continue;

				if (Objective->BackendName == BackendName)
				{
					Objective->AchievedCount += Count;
					Objective->bActive = bActive;
					Objective->DisplayDynamicQuestUpdate();
				}
			}
		}
		else
			LogWarning("QuestHandler::ProgressQuest: QuestItem is NULL, quest not progressed.");

		QuestManager->ForceTriggerQuestsUpdated();
	}

	void (*oSendCustomStatEvent)(UObject* Object, FFrame& Stack);
	void hkSendCustomStatEvent(UObject* Object, FFrame& Stack)
	{
		struct FDataTableRowHandle ObjectiveStat;
		int32 Count;
		bool bForceFlush;
		Stack.StepCompiledIn(&ObjectiveStat);
		Stack.StepCompiledIn(&Count);
		Stack.StepCompiledIn(&bForceFlush);

		auto QuestManager = reinterpret_cast<UFortQuestManager*>(Object);

		LogInfo("SendCustomStatEvent: ObjectiveStat.RowName: {}", ObjectiveStat.RowName.ToString());
		LogInfo("SendCustomStatEvent: Count: {}", Count);
		LogInfo("SendCustomStatEvent: bForceFlush: {}", bForceFlush);

		TArray<UFortQuestItem*> CurrentQuests;
		QuestManager->GetCurrentQuests(&CurrentQuests);

		if (CurrentQuests.IsValid())
		{
			for (int i = 0; i < CurrentQuests.Num(); i++)
			{
				UFortQuestItem* CurrentQuest = CurrentQuests[i];
				if (!CurrentQuest)
					continue;

				UFortQuestItemDefinition* QuestDefinition = CurrentQuest->GetQuestDefinitionBP();
				if (!QuestDefinition)
					continue;

				for (int i = 0; i < QuestDefinition->Objectives.Num(); i++)
				{
					FFortMcpQuestObjectiveInfo ObjectiveInfo = QuestDefinition->Objectives[i];
					FDataTableRowHandle ObjectStatHandle = ObjectiveInfo.ObjectiveStatHandle;
					UDataTable* DataTable = ObjectStatHandle.DataTable;
					if (!DataTable)
						continue;

					auto& RowMap = DataTable->RowMap;
					FFortQuestObjectiveStatTableRow* Row = nullptr;

					if (RowMap.Num() <= 0)
						continue;

					for (int i = 0; i < RowMap.Num(); ++i)
					{
						auto& Pair = RowMap[i];
						if (Pair.Key() == ObjectiveStat.RowName)
						{
							Row = reinterpret_cast<FFortQuestObjectiveStatTableRow*>(Pair.Second);
							break;
						}
					}

					if (Row)
					{
						LogInfo("Found Stuff");
						for (int i = 0; i < CurrentQuest->Objectives.Num(); i++)
						{
							UFortQuestObjectiveInfo* Objective = CurrentQuest->Objectives[i];
							if (!Objective)
								continue;
							
							FName BackendName = Objective->BackendName;

							Objective->AchievedCount += Count;
							Objective->DisplayDynamicQuestUpdate();
						}
						QuestManager->ForceTriggerQuestsUpdated();

						return oSendCustomStatEvent(Object, Stack);
					}
				}
			}
		}

		return oSendCustomStatEvent(Object, Stack);
	}

	void (*oSendComplexCustomStatEvent)(UObject* Object, FFrame& Stack);
	void hkSendComplexCustomStatEvent(UObject* Object, FFrame& Stack)
	{
		class UObject* TargetObject;
		struct FGameplayTagContainer                  AdditionalSourceTags;
		struct FGameplayTagContainer                  TargetTags;
		bool                                          QuestActive;
		bool                                          QuestCompleted;
		int32                                         Count;

		Stack.StepCompiledIn(&TargetObject);
		Stack.StepCompiledIn(&AdditionalSourceTags);
		Stack.StepCompiledIn(&TargetTags);
		Stack.StepCompiledIn(&QuestActive);
		Stack.StepCompiledIn(&QuestCompleted);
		Stack.StepCompiledIn(&Count);

		auto QuestManager = reinterpret_cast<UFortQuestManager*>(Object);
		LogInfo("SendComplexCustomStatEvent: TargetObject: {}", TargetObject->GetFullName());

		if (TargetTags.GameplayTags.IsValid())
		{
			LogInfo("SendComplexCustomStatEvent: TargetTags:GameplayTags are valid.");

			for (int i = 0; i < TargetTags.GameplayTags.Num(); i++)
			{
				LogInfo("TargetTags:GameplayTags [{}]: {}", i, TargetTags.GameplayTags[i].TagName.ToString());
			}
		}

		if (TargetTags.ParentTags.IsValid())
		{
			LogInfo("SendComplexCustomStatEvent: TargetTags:ParentTags are valid.");

			for (int i = 0; i < TargetTags.ParentTags.Num(); i++)
			{
				LogInfo("TargetTags:ParentTags [{}]: {}", i, TargetTags.ParentTags[i].TagName.ToString());
			}
		}

		if (AdditionalSourceTags.GameplayTags.IsValid())
		{
			LogInfo("SendComplexCustomStatEvent: AdditionalSourceTags:GameplayTags are valid.");

			for (int i = 0; i < AdditionalSourceTags.GameplayTags.Num(); i++)
			{
				LogInfo("AdditionalSourceTags:GameplayTags [{}]: {}", i, AdditionalSourceTags.GameplayTags[i].TagName.ToString());
			}
		}

		if (AdditionalSourceTags.ParentTags.IsValid())
		{
			LogInfo("SendComplexCustomStatEvent: AdditionalSourceTags:ParentTags are valid.");

			for (int i = 0; i < AdditionalSourceTags.ParentTags.Num(); i++)
			{
				LogInfo("AdditionalSourceTags:ParentTags [{}]: {}", i, AdditionalSourceTags.ParentTags[i].TagName.ToString());
			}
		}

		LogInfo("SendComplexCustomStatEvent: QuestActive: {}", QuestActive);
		LogInfo("SendComplexCustomStatEvent: QuestCompleted: {}", QuestCompleted);
		LogInfo("SendComplexCustomStatEvent: Count: {}", Count);

		TArray<UFortQuestItem*> CurrentQuests;
		QuestManager->GetCurrentQuests(&CurrentQuests);

		if (CurrentQuests.IsValid())
		{
			for (int i = 0; i < CurrentQuests.Num(); i++)
			{
				UFortQuestItem* CurrentQuest = CurrentQuests[i];
				if (!CurrentQuest)
					continue;

				UFortQuestItemDefinition* QuestDefinition = CurrentQuest->GetQuestDefinitionBP();
				if (!QuestDefinition)
					continue;

				for (int i = 0; i < QuestDefinition->Objectives.Num(); i++)
				{
					FFortMcpQuestObjectiveInfo ObjectiveInfo = QuestDefinition->Objectives[i];
					FDataTableRowHandle ObjectStatHandle = ObjectiveInfo.ObjectiveStatHandle;
					UDataTable* DataTable = ObjectStatHandle.DataTable;
					if (!DataTable)
						continue;

					auto& RowMap = DataTable->RowMap;
					FFortQuestObjectiveStatTableRow* Row = nullptr;

					if (RowMap.Num() <= 0)
						continue;

					for (int i = 0; i < RowMap.Num(); ++i)
					{
						auto& Pair = RowMap[i];
						if (Pair.Key() == ObjectStatHandle.RowName)
						{
							Row = reinterpret_cast<FFortQuestObjectiveStatTableRow*>(Pair.Second);
							break;
						}
					}

					if (Row)
					{
						if (Row->TargetTagContainer.GameplayTags.IsValid() && Row->TargetTagContainer.GameplayTags.IsValidIndex(0))
						{
							if (Row->TargetTagContainer.GameplayTags[0].TagName == TargetTags.GameplayTags[0].TagName)
							{
								for (int i = 0; i < CurrentQuest->Objectives.Num(); i++)
								{
									UFortQuestObjectiveInfo* Objective = CurrentQuest->Objectives[i];
									if (!Objective)
										continue;

									FName BackendName = Objective->BackendName;

									Objective->AchievedCount += Count;
									Objective->bActive = QuestActive;
									Objective->DisplayDynamicQuestUpdate();
								}
								QuestManager->ForceTriggerQuestsUpdated();

								return oSendComplexCustomStatEvent(Object, Stack);
							}
						}
					}
				}
			}
		}

		return oSendComplexCustomStatEvent(Object, Stack);
	}

	void Initialize()
	{
		static auto SendCustomStatEventFunc = UObject::FindObject<UFunction>("Function FortniteGame.FortQuestManager.SendCustomStatEvent");
		static auto SendComplexCustomStatEventFunc = UObject::FindObject<UFunction>("Function FortniteGame.FortQuestManager.SendComplexCustomStatEvent");

		HookingManager::ExecHook(SendCustomStatEventFunc, hkSendCustomStatEvent, oSendCustomStatEvent);
		HookingManager::ExecHook(SendComplexCustomStatEventFunc, hkSendComplexCustomStatEvent, oSendComplexCustomStatEvent);
	}
}