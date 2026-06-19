RocketHideout_B1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RocketHideout_B1F_Frlg_OnTransition
	.byte 0

RocketHideout_B1F_Frlg_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	end

RocketHideout_B1F_Frlg_EventScript_Rival_text_1::
	msgbox RocketHideout_B1F_Frlg_Text_Rival, MSGBOX_NPC
	end

RocketHideout_B1F_Frlg_Text_Rival:
	.string "Hola, {PLAYER}, si buscas al cientifico,\n"
	.string "esta ahi abajo.$"

RocketHideout_B1F_Frlg_Text_Rival:
	.string "Bien, ¡ya tienes Vuelo!\p"
	.string "Entonces, busquemos a un idiota\n"
	.string "y robemos su Pokémon Volador.$"

RocketHideout_B1F_Frlg_EventScript_Grunt_text_1::
	msgbox RocketHideout_B1F_Frlg_Text_Recluta_1, MSGBOX_NPC
	end

RocketHideout_B1F_Frlg_Text_Recluta_1:
	.string "Recuerdo mi primer robo como si\n"
	.string "fuera ayer.\p"
	.string "No hay nada más satisfactorio que\n"
	.string "huir del pobre bastardo al que le\l"
	.string "has robado.\p"
	.string "Aunque nada es perfecto. Este Pokémon\n"
	.string "no me hace caso, ¡Tendré que forzar su\l"
	.string "obediencia!$"

RocketHideout_B1F_Frlg_EventScript_Grunt_text_2::
	msgbox RocketHideout_B1F_Frlg_Text_Recluta_2, MSGBOX_NPC
	end

RocketHideout_B1F_Frlg_Text_Recluta_2:
	.string "Ja, vas a robar tu primer Pokémon,\n"
	.string "¿verdad?\p"
	.string "Toma nota: Como Soldado, se te\n"
	.string "recomienda robar a entrenadores\l"
	.string "débiles, como niños y ancianos.\p"
	.string "Si lo intentas con alguien más, lo\n"
	.string "más probable es que no la cuentes.$"

RocketHideout_B1F_Frlg_EventScript_Grunt_text_3::
	msgbox RocketHideout_B1F_Frlg_Text_Recluta_3, MSGBOX_NPC
	end

RocketHideout_B1F_Frlg_EventScript_Vuelo_ScriptGatillo::
    lock
    applymovement LOCALID_SUPER_NERD, Common_Movement_FaceLeft
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox RocketHideout_B1F_Frlg_Text_Cientifico_1, MSGBOX_AUTOCLOSE
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	applymovement LOCALID_SUPER_NERD, RocketHideout_B1F_Frlg_Movement_NerdMov_1
	waitmovement 0
	msgbox RocketHideout_B1F_Frlg_Text_Cientifico_2, MSGBOX_AUTOCLOSE
	applymovement LOCALID_SUPER_NERD, RocketHideout_B1F_Frlg_Movement_NerdMov_2
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox RocketHideout_B1F_Frlg_Text_Cientifico_3, MSGBOX_AUTOCLOSE
	giveitem ITEM_HM_FLY
	setflag FLAG_RECEIVED_HM_FLY
	msgbox RocketHideout_B1F_Frlg_Text_Cientifico_4, MSGBOX_AUTOCLOSE
	setvar VAR_MAP_SCENE_GUARIDA_ROCKET_VUELO, 1
	releaseall
	end

RocketHideout_B1F_Frlg_Text_Recluta_3:
	.string "¡Ey, Soldado! ¿que crees que haces?\n"
	.string "¡Tienes cosas que hacer!\p"
	.string "¡No pierdas tiempo, o conocerás el\n"
	.string "peor lado de Petrel!$"

RocketHideout_B1F_Frlg_Text_Cientifico_1:
	.string "Vienes por Vuelo, ¿no?\p"
	.string "Si, tengo esa MO, dejame ir\n"
	.string "por ella.$"

RocketHideout_B1F_Frlg_Text_Cientifico_2:
	.string "Vuelo gratis para todos…\p"
	.string "Dios, Giovanni\n"
	.string "se está ablandando…$"

RocketHideout_B1F_Frlg_Text_Cientifico_3:
	.string "Aquí tienes. ¡No la desperdicies!$"

RocketHideout_B1F_Frlg_Text_Cientifico_4:
	.string "¡Ahora sal de aquí!\p"
	.string "Tengo cosas que hacer.$"

RocketHideout_B1F_Frlg_Movement_NerdMov_1::
	walk_down
	walk_down
	walk_right
	walk_right
    delay_8
	walk_in_place_right
	step_end

RocketHideout_B1F_Frlg_Movement_NerdMov_2::
	walk_left
	walk_left
	walk_up
	walk_up
    delay_8
	walk_in_place_left
	step_end
