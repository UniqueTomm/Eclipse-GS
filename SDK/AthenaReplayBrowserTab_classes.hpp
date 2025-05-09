#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: AthenaReplayBrowserTab

#include "Basic.hpp"

#include "FortniteGame_structs.hpp"
#include "CommonInput_structs.hpp"
#include "UMG_structs.hpp"
#include "Engine_structs.hpp"
#include "FortniteUI_classes.hpp"
#include "CommonUI_structs.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass AthenaReplayBrowserTab.AthenaReplayBrowserTab_C
// 0x00B8 (0x04D8 - 0x0420)
class UAthenaReplayBrowserTab_C final : public UAthenaReplayBrowserScreenBase
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0420(0x0008)(Transient, DuplicateTransient)
	class UCommonTextBlock*                       AverageKills;                                      // 0x0428(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonTextBlock*                       AverageLength;                                     // 0x0430(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonTextBlock*                       AverageRank;                                       // 0x0438(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonTextBlock*                       AverageViews;                                      // 0x0440(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class ULeaderboardThrobber_C*                 LoadingThrobber;                                   // 0x0448(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonBorder*                          LowerBarBorder;                                    // 0x0450(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UAthenaReplayBrowserMatchStats_C*       MatchStats;                                        // 0x0458(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UIconTextButton_C*                      OpenReplayFolder;                                  // 0x0460(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UAthenaReplayBrowserRenameDialog_C*     RenameDialog;                                      // 0x0468(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonListView*                        ReplayListView;                                    // 0x0470(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonTextBlock*                       TotalSize;                                         // 0x0478(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UAthenaReplayBrowserRowProxyInstance*   SelectedRowProxy;                                  // 0x0480(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FDataTableRowHandle                    InputPlay;                                         // 0x0488(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor)
	struct FDataTableRowHandle                    InputDelete;                                       // 0x0498(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor)
	struct FDataTableRowHandle                    InputRename;                                       // 0x04A8(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor)
	class UAthenaReplayBrowserOldReplayDisclaimer_C* OldReplayDisclaimer;                               // 0x04B8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FDataTableRowHandle                    InputBack;                                         // 0x04C0(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor)
	struct FTimerHandle                           LoadingTimerHandle;                                // 0x04D0(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor)

public:
	void ExecuteUbergraph_AthenaReplayBrowserTab(int32 EntryPoint);
	void ShowErrorDialog(const class FText& Title, const class FText& MESSAGE);
	void BndEvt__OpenReplayFolder_K2Node_ComponentBoundEvent_20_CommonButtonClicked__DelegateSignature(class UCommonButton* Button);
	void OnReplayEnumerationFinish();
	void OnReplayEnumerationStart();
	void OnPlayFailed(const class FText& Reason);
	void BndEvt__ReplayListView_K2Node_ComponentBoundEvent_0_OnListViewItemSelected__DelegateSignature(class UObject* Item, bool bIsSelected);
	void OnCorruptReplayFound(const class FText& Info);
	void OnRowsUpdated();
	void OnSaveFailed(const class FText& Reason);
	void OnRenameFailed(const class FText& Reason);
	void OnDeleteFailed(const class FText& Reason);
	void OnActivated();
	void DeleteReplay(const class UAthenaReplayBrowserRowProxyInstance* RowProxy);
	void BndEvt__ReplayListView_K2Node_ComponentBoundEvent_0_OnListViewItemClicked__DelegateSignature(class UObject* Item);
	void OnInputModeChanged(bool bUsingGamepad);
	void PlayReplay(const class UAthenaReplayBrowserRowProxyInstance* RowProxy);
	void Construct();
	void BndEvt__CommonListView_0_K2Node_ComponentBoundEvent_2_OnListViewItemClicked__DelegateSignature(class UObject* Item);
	void DialogResult_0F41323B4319A691C289608E8CEED0CB(EFortDialogResult Result, class FName ResultName);
	void DialogResult_79A680104EAA90FF10D265808FD512BC(EFortDialogResult Result, class FName ResultName);
	void DialogResult_C4C0E9C14BA061EBBA451D839890A4A7(EFortDialogResult Result, class FName ResultName);
	void DialogResult_961693C14B8B2A8E26E2AFB69251D5F8(EFortDialogResult Result, class FName ResultName);
	void DialogResult_00986FB1494FF7EA41F1769EAFB70E83(EFortDialogResult Result, class FName ResultName);
	void DialogResult_E89869AF460753E34CA097BC86722E95(EFortDialogResult Result, class FName ResultName);
	void DialogResult_12ECDF8D47346477E6D96B927F5223CE(EFortDialogResult Result, class FName ResultName);
	void DialogResult_580DD63848C06A1FCA8D9DABDAF6FF77(EFortDialogResult Result, class FName ResultName);
	void Refresh();
	void OnInputDelete(bool* bPassThrough);
	void OnInputRename(bool* bPassThrough);
	void SelectReplay(class UObject* ReplayInfoObject);
	void FocusList();
	void InitializeInput();
	void OnInputPlay(bool* bPassThrough);
	void OnConfirmRename(class UAthenaReplayBrowserRowProxyInstance* RowProxy, const class FText& NewName);
	void CloseRenameDialog();
	void SetupInputActionHandlers();
	void OnInputBack(bool* bPassThrough);
	void OnEnumerationStateChanged(bool EnumerationInProgress);
	void OnShowLoadingThrobber();
	void DoesSupportReplayFolder(bool* IsSupported);
	void RefreshReplayFolderState();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"AthenaReplayBrowserTab_C">();
	}
	static class UAthenaReplayBrowserTab_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UAthenaReplayBrowserTab_C>();
	}
};
static_assert(alignof(UAthenaReplayBrowserTab_C) == 0x000008, "Wrong alignment on UAthenaReplayBrowserTab_C");
static_assert(sizeof(UAthenaReplayBrowserTab_C) == 0x0004D8, "Wrong size on UAthenaReplayBrowserTab_C");
static_assert(offsetof(UAthenaReplayBrowserTab_C, UberGraphFrame) == 0x000420, "Member 'UAthenaReplayBrowserTab_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(UAthenaReplayBrowserTab_C, AverageKills) == 0x000428, "Member 'UAthenaReplayBrowserTab_C::AverageKills' has a wrong offset!");
static_assert(offsetof(UAthenaReplayBrowserTab_C, AverageLength) == 0x000430, "Member 'UAthenaReplayBrowserTab_C::AverageLength' has a wrong offset!");
static_assert(offsetof(UAthenaReplayBrowserTab_C, AverageRank) == 0x000438, "Member 'UAthenaReplayBrowserTab_C::AverageRank' has a wrong offset!");
static_assert(offsetof(UAthenaReplayBrowserTab_C, AverageViews) == 0x000440, "Member 'UAthenaReplayBrowserTab_C::AverageViews' has a wrong offset!");
static_assert(offsetof(UAthenaReplayBrowserTab_C, LoadingThrobber) == 0x000448, "Member 'UAthenaReplayBrowserTab_C::LoadingThrobber' has a wrong offset!");
static_assert(offsetof(UAthenaReplayBrowserTab_C, LowerBarBorder) == 0x000450, "Member 'UAthenaReplayBrowserTab_C::LowerBarBorder' has a wrong offset!");
static_assert(offsetof(UAthenaReplayBrowserTab_C, MatchStats) == 0x000458, "Member 'UAthenaReplayBrowserTab_C::MatchStats' has a wrong offset!");
static_assert(offsetof(UAthenaReplayBrowserTab_C, OpenReplayFolder) == 0x000460, "Member 'UAthenaReplayBrowserTab_C::OpenReplayFolder' has a wrong offset!");
static_assert(offsetof(UAthenaReplayBrowserTab_C, RenameDialog) == 0x000468, "Member 'UAthenaReplayBrowserTab_C::RenameDialog' has a wrong offset!");
static_assert(offsetof(UAthenaReplayBrowserTab_C, ReplayListView) == 0x000470, "Member 'UAthenaReplayBrowserTab_C::ReplayListView' has a wrong offset!");
static_assert(offsetof(UAthenaReplayBrowserTab_C, TotalSize) == 0x000478, "Member 'UAthenaReplayBrowserTab_C::TotalSize' has a wrong offset!");
static_assert(offsetof(UAthenaReplayBrowserTab_C, SelectedRowProxy) == 0x000480, "Member 'UAthenaReplayBrowserTab_C::SelectedRowProxy' has a wrong offset!");
static_assert(offsetof(UAthenaReplayBrowserTab_C, InputPlay) == 0x000488, "Member 'UAthenaReplayBrowserTab_C::InputPlay' has a wrong offset!");
static_assert(offsetof(UAthenaReplayBrowserTab_C, InputDelete) == 0x000498, "Member 'UAthenaReplayBrowserTab_C::InputDelete' has a wrong offset!");
static_assert(offsetof(UAthenaReplayBrowserTab_C, InputRename) == 0x0004A8, "Member 'UAthenaReplayBrowserTab_C::InputRename' has a wrong offset!");
static_assert(offsetof(UAthenaReplayBrowserTab_C, OldReplayDisclaimer) == 0x0004B8, "Member 'UAthenaReplayBrowserTab_C::OldReplayDisclaimer' has a wrong offset!");
static_assert(offsetof(UAthenaReplayBrowserTab_C, InputBack) == 0x0004C0, "Member 'UAthenaReplayBrowserTab_C::InputBack' has a wrong offset!");
static_assert(offsetof(UAthenaReplayBrowserTab_C, LoadingTimerHandle) == 0x0004D0, "Member 'UAthenaReplayBrowserTab_C::LoadingTimerHandle' has a wrong offset!");

}

