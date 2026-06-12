RocketHideout_B1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RocketHideout_B1F_Frlg_OnTransition
	.byte 0

RocketHideout_B1F_Frlg_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	end

RocketHideout_B1F_Frlg_EventScript_Rival_text_1::
	msgbox RocketHideout_B1F_Frlg_Text_Rival, MSGBOX_DEFAULT
	end

RocketHideout_B1F_Frlg_Text_Rival:
	.string "Hola, {PLAYER}, si buscas al cientifico,\n"
	.string "esta ahi abajo.$"