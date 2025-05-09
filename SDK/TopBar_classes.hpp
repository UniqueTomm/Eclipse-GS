#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: TopBar

#include "Basic.hpp"

#include "CommonInput_structs.hpp"
#include "UMG_structs.hpp"
#include "FortniteGame_structs.hpp"
#include "Engine_structs.hpp"
#include "SlateCore_structs.hpp"
#include "FortniteUI_structs.hpp"
#include "FortniteUI_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass TopBar.TopBar_C
// 0x0178 (0x0578 - 0x0400)
class UTopBar_C final : public UFortTopBarPanel
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0400(0x0008)(Transient, DuplicateTransient)
	class UWidgetAnimation*                       IntroSocialPanel;                                  // 0x0408(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWidgetAnimation*                       PartyJoinFlash;                                    // 0x0410(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWidgetAnimation*                       IntroMainMenu;                                     // 0x0418(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UBorder*                                Border_SocialPanel;                                // 0x0420(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UBP_FortLiveStreamGrantWindowExpires_C* BP_FortLiveStreamGrantWindowExpires;               // 0x0428(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UBRCurrency_C*                          BRCurrency;                                        // 0x0430(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UImage*                                 FortniteLogo;                                      // 0x0438(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UFortSZAwareImage*                      FriendInviteBang;                                  // 0x0440(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UHorizontalBox*                         HorizontalBoxRatingIcons;                          // 0x0448(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class ULobbyTimer_C*                          LobbyTimer_112;                                    // 0x0450(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMainMenu_C*                            MainMenu;                                          // 0x0458(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonBorder*                          MainMenuBorder;                                    // 0x0460(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UIconTextButton_C*                      MainMenuButton;                                    // 0x0468(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class USpacer*                                MainMenuSpacer;                                    // 0x0470(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMiniPartyBar_C*                        MiniPartyBar;                                      // 0x0478(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UMTXButton_C*                           MTXButton;                                         // 0x0480(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class USizeBox*                               MTXButtonContainer;                                // 0x0488(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonBorder*                          PartyFlash;                                        // 0x0490(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UPowerWidget_C*                         PowerWidget;                                       // 0x0498(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class USafeZone*                              SafeZone_0;                                        // 0x04A0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class USafeZone*                              SafeZone_1;                                        // 0x04A8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class USafeZone*                              SafeZoneRatingIcons;                               // 0x04B0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UScaleBox*                              ScaleBox_Social;                                   // 0x04B8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class USizeBox*                               SizeBox_Social;                                    // 0x04C0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UIconTextButton_C*                      Social;                                            // 0x04C8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class USocialPanel_C*                         SocialPanel;                                       // 0x04D0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UBackgroundBlur*                        Top;                                               // 0x04D8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UTopBarSkillPoints_C*                   TopBarSkillPoints;                                 // 0x04E0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonBorder*                          TouchZone;                                         // 0x04E8(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWindowchromebuttons_C*                 Windowchromebuttons;                               // 0x04F0(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	bool                                          MainMenuShown;                                     // 0x04F8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_4F9[0x7];                                      // 0x04F9(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class USoundBase*                             Sound_StoreButtonClicked_Error;                    // 0x0500(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class USoundBase*                             Sound_StoreMusic;                                  // 0x0508(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFort_Entry_Music_Controller_BP_C*      Fort_Entry_Music_Controller;                       // 0x0510(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	EFrontEndCamera                               LastNavigationRequestCameraState;                  // 0x0518(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_519[0x7];                                      // 0x0519(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FTimerHandle                           HeroSquadPulseTimer;                               // 0x0520(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor)
	struct FTimerHandle                           DisableHeroSquadPulseTimer;                        // 0x0528(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor)
	UMulticastDelegateProperty_                   MainMenuStateChanged;                              // 0x0530(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, BlueprintAssignable, BlueprintCallable)
	class UFortGameFeedbackBase*                  FeedbackWidget;                                    // 0x0540(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         FEdgePower;                                        // 0x0548(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_54C[0x4];                                      // 0x054C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	UMulticastDelegateProperty_                   OpenAccountPicker;                                 // 0x0550(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, BlueprintAssignable, BlueprintCallable)
	bool                                          UseAnimation;                                      // 0x0560(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	bool                                          IsMainMenuOpen;                                    // 0x0561(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_562[0x2];                                      // 0x0562(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	struct FMargin                                IconPadding;                                       // 0x0564(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	bool                                          BROnly;                                            // 0x0574(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)

public:
	void MainMenuStateChanged__DelegateSignature(bool Open);
	void OpenAccountPicker__DelegateSignature();
	void ExecuteUbergraph_TopBar(int32 EntryPoint);
	void On_Social_Panel_Closed();
	void BndEvt__MainMenu_K2Node_ComponentBoundEvent_0_OnRequestShowSocialWidget__DelegateSignature();
	void ManualToggleMainMenu();
	void AddIconToScreen(class UCommonLazyImage* Image);
	void Construct();
	void On_Power_Increased();
	void ShowSocialConfirmation(const class FText& MESSAGE);
	void BndEvt__BP_FortLiveStreamGrantWindowExpires_K2Node_ComponentBoundEvent_108_StreamTimerExpired__DelegateSignature();
	void BndEvt__BP_FortLiveStreamGrantWindowExpires_K2Node_ComponentBoundEvent_101_StreamTimerStarted__DelegateSignature();
	void OnAnimationFinished(const class UWidgetAnimation* Animation);
	void Destruct();
	void PreConstruct(bool IsDesignTime);
	void BndEvt__MainMenuButton_K2Node_ComponentBoundEvent_70_CommonButtonClicked__DelegateSignature(class UCommonButton* Button);
	void BndEvt__Social_K2Node_ComponentBoundEvent_64_CommonButtonClicked__DelegateSignature(class UCommonButton* Button);
	void BndEvt__MainMenu_K2Node_ComponentBoundEvent_48_OnRequestShowFeedbackWidget__DelegateSignature();
	void Hidden();
	void OnActivated();
	void OnBeginOutro();
	void OnBeginIntro();
	void DialogResult_32D813B145A5E184B01A15AABE16B774(EFortDialogResult Result, class FName ResultName);
	void OpenMainMenu();
	void CloseMainMenu();
	void BindPanelControl();
	void HandleCloseAction(bool* Passthrough);
	void CreateWidgets();
	void ForceMenuOpen();
	void BindNavigationDelegates();
	void UnbindNavigationDelegates();
	void HandleFeatureSwitchOp(EFortUIFeature Feature);
	void HandleSwitchProfileAction(bool* Passthrough);
	void BindSwitchProfileAction();
	void BindActiveFriendsCountChangedEvent();
	void HandleActiveFriendsCountChanged(int32 ActiveFriendsCount);
	void UnbindActiveFriendsCountChangedEvent();
	void HandleAccountPickerResult(int32 ControllerIndex, bool UserSwitched);
	void HandleActiveInvitesCountChanged(int32 ActiveInvitesCount);
	class UWidget* GetFriendsTooltipWidget();
	class UWidget* GetMainMenuTooltipWidget();
	void ForceMenuClosed();
	void HideMTXPlusButton();
	void FireOpenAnalyticsEvent();
	void OpenSocialMenu();
	void ConfigureVisibleItemsForSubGame();
	void Set_Header_Visibility(bool Param_Visibility);
	void CloseSocialMenu();
	void HandleMainMenuAnimComplete();
	void HandleSocialPanelAnimComplete();
	struct FEventReply On_TouchZone_MouseButtonDown_0(const struct FGeometry& MyGeometry, const struct FPointerEvent& MouseEvent);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"TopBar_C">();
	}
	static class UTopBar_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UTopBar_C>();
	}
};
static_assert(alignof(UTopBar_C) == 0x000008, "Wrong alignment on UTopBar_C");
static_assert(sizeof(UTopBar_C) == 0x000578, "Wrong size on UTopBar_C");
static_assert(offsetof(UTopBar_C, UberGraphFrame) == 0x000400, "Member 'UTopBar_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(UTopBar_C, IntroSocialPanel) == 0x000408, "Member 'UTopBar_C::IntroSocialPanel' has a wrong offset!");
static_assert(offsetof(UTopBar_C, PartyJoinFlash) == 0x000410, "Member 'UTopBar_C::PartyJoinFlash' has a wrong offset!");
static_assert(offsetof(UTopBar_C, IntroMainMenu) == 0x000418, "Member 'UTopBar_C::IntroMainMenu' has a wrong offset!");
static_assert(offsetof(UTopBar_C, Border_SocialPanel) == 0x000420, "Member 'UTopBar_C::Border_SocialPanel' has a wrong offset!");
static_assert(offsetof(UTopBar_C, BP_FortLiveStreamGrantWindowExpires) == 0x000428, "Member 'UTopBar_C::BP_FortLiveStreamGrantWindowExpires' has a wrong offset!");
static_assert(offsetof(UTopBar_C, BRCurrency) == 0x000430, "Member 'UTopBar_C::BRCurrency' has a wrong offset!");
static_assert(offsetof(UTopBar_C, FortniteLogo) == 0x000438, "Member 'UTopBar_C::FortniteLogo' has a wrong offset!");
static_assert(offsetof(UTopBar_C, FriendInviteBang) == 0x000440, "Member 'UTopBar_C::FriendInviteBang' has a wrong offset!");
static_assert(offsetof(UTopBar_C, HorizontalBoxRatingIcons) == 0x000448, "Member 'UTopBar_C::HorizontalBoxRatingIcons' has a wrong offset!");
static_assert(offsetof(UTopBar_C, LobbyTimer_112) == 0x000450, "Member 'UTopBar_C::LobbyTimer_112' has a wrong offset!");
static_assert(offsetof(UTopBar_C, MainMenu) == 0x000458, "Member 'UTopBar_C::MainMenu' has a wrong offset!");
static_assert(offsetof(UTopBar_C, MainMenuBorder) == 0x000460, "Member 'UTopBar_C::MainMenuBorder' has a wrong offset!");
static_assert(offsetof(UTopBar_C, MainMenuButton) == 0x000468, "Member 'UTopBar_C::MainMenuButton' has a wrong offset!");
static_assert(offsetof(UTopBar_C, MainMenuSpacer) == 0x000470, "Member 'UTopBar_C::MainMenuSpacer' has a wrong offset!");
static_assert(offsetof(UTopBar_C, MiniPartyBar) == 0x000478, "Member 'UTopBar_C::MiniPartyBar' has a wrong offset!");
static_assert(offsetof(UTopBar_C, MTXButton) == 0x000480, "Member 'UTopBar_C::MTXButton' has a wrong offset!");
static_assert(offsetof(UTopBar_C, MTXButtonContainer) == 0x000488, "Member 'UTopBar_C::MTXButtonContainer' has a wrong offset!");
static_assert(offsetof(UTopBar_C, PartyFlash) == 0x000490, "Member 'UTopBar_C::PartyFlash' has a wrong offset!");
static_assert(offsetof(UTopBar_C, PowerWidget) == 0x000498, "Member 'UTopBar_C::PowerWidget' has a wrong offset!");
static_assert(offsetof(UTopBar_C, SafeZone_0) == 0x0004A0, "Member 'UTopBar_C::SafeZone_0' has a wrong offset!");
static_assert(offsetof(UTopBar_C, SafeZone_1) == 0x0004A8, "Member 'UTopBar_C::SafeZone_1' has a wrong offset!");
static_assert(offsetof(UTopBar_C, SafeZoneRatingIcons) == 0x0004B0, "Member 'UTopBar_C::SafeZoneRatingIcons' has a wrong offset!");
static_assert(offsetof(UTopBar_C, ScaleBox_Social) == 0x0004B8, "Member 'UTopBar_C::ScaleBox_Social' has a wrong offset!");
static_assert(offsetof(UTopBar_C, SizeBox_Social) == 0x0004C0, "Member 'UTopBar_C::SizeBox_Social' has a wrong offset!");
static_assert(offsetof(UTopBar_C, Social) == 0x0004C8, "Member 'UTopBar_C::Social' has a wrong offset!");
static_assert(offsetof(UTopBar_C, SocialPanel) == 0x0004D0, "Member 'UTopBar_C::SocialPanel' has a wrong offset!");
static_assert(offsetof(UTopBar_C, Top) == 0x0004D8, "Member 'UTopBar_C::Top' has a wrong offset!");
static_assert(offsetof(UTopBar_C, TopBarSkillPoints) == 0x0004E0, "Member 'UTopBar_C::TopBarSkillPoints' has a wrong offset!");
static_assert(offsetof(UTopBar_C, TouchZone) == 0x0004E8, "Member 'UTopBar_C::TouchZone' has a wrong offset!");
static_assert(offsetof(UTopBar_C, Windowchromebuttons) == 0x0004F0, "Member 'UTopBar_C::Windowchromebuttons' has a wrong offset!");
static_assert(offsetof(UTopBar_C, MainMenuShown) == 0x0004F8, "Member 'UTopBar_C::MainMenuShown' has a wrong offset!");
static_assert(offsetof(UTopBar_C, Sound_StoreButtonClicked_Error) == 0x000500, "Member 'UTopBar_C::Sound_StoreButtonClicked_Error' has a wrong offset!");
static_assert(offsetof(UTopBar_C, Sound_StoreMusic) == 0x000508, "Member 'UTopBar_C::Sound_StoreMusic' has a wrong offset!");
static_assert(offsetof(UTopBar_C, Fort_Entry_Music_Controller) == 0x000510, "Member 'UTopBar_C::Fort_Entry_Music_Controller' has a wrong offset!");
static_assert(offsetof(UTopBar_C, LastNavigationRequestCameraState) == 0x000518, "Member 'UTopBar_C::LastNavigationRequestCameraState' has a wrong offset!");
static_assert(offsetof(UTopBar_C, HeroSquadPulseTimer) == 0x000520, "Member 'UTopBar_C::HeroSquadPulseTimer' has a wrong offset!");
static_assert(offsetof(UTopBar_C, DisableHeroSquadPulseTimer) == 0x000528, "Member 'UTopBar_C::DisableHeroSquadPulseTimer' has a wrong offset!");
static_assert(offsetof(UTopBar_C, MainMenuStateChanged) == 0x000530, "Member 'UTopBar_C::MainMenuStateChanged' has a wrong offset!");
static_assert(offsetof(UTopBar_C, FeedbackWidget) == 0x000540, "Member 'UTopBar_C::FeedbackWidget' has a wrong offset!");
static_assert(offsetof(UTopBar_C, FEdgePower) == 0x000548, "Member 'UTopBar_C::FEdgePower' has a wrong offset!");
static_assert(offsetof(UTopBar_C, OpenAccountPicker) == 0x000550, "Member 'UTopBar_C::OpenAccountPicker' has a wrong offset!");
static_assert(offsetof(UTopBar_C, UseAnimation) == 0x000560, "Member 'UTopBar_C::UseAnimation' has a wrong offset!");
static_assert(offsetof(UTopBar_C, IsMainMenuOpen) == 0x000561, "Member 'UTopBar_C::IsMainMenuOpen' has a wrong offset!");
static_assert(offsetof(UTopBar_C, IconPadding) == 0x000564, "Member 'UTopBar_C::IconPadding' has a wrong offset!");
static_assert(offsetof(UTopBar_C, BROnly) == 0x000574, "Member 'UTopBar_C::BROnly' has a wrong offset!");

}

