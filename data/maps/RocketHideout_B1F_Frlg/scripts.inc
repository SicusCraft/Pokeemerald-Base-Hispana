RocketHideout_B1F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RocketHideout_B1F_Frlg_OnTransition
	.byte 0

RocketHideout_B1F_Frlg_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	end

RocketHideout_B1F_Frlg_EventScript_Rival_text_1::
    lock
    goto_if_set FLAG_RECEIVED_HM_FLY, RocketHideout_B1F_Frlg_EventScript_Rival_text_2
	msgbox RocketHideout_B1F_Frlg_Text_Rival, MSGBOX_NPC
	end

RocketHideout_B1F_Frlg_EventScript_Rival_text_2::
	msgbox RocketHideout_B1F_Frlg_Text_Rival_2, MSGBOX_NPC
	delay 10
	RocketHideout_B1F_Frlg_Text_Ronnie_1, MSGBOX_NPC
	applymovement LOCALID_OAKS_LAB_RIVAL, Common_Movement_FaceRight
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, RocketHideout_B1F_Frlg_EventScript_Player_mov_ronnie_1
	call_if_eq VAR_FACING, DIR_EAST, RocketHideout_B1F_Frlg_EventScript_Player_mov_ronnie_2
	applymovement LOCALID_OAKS_LAB_RIVAL, RocketHideout_B1F_Frlg_Movement_ronnie_1
	waitmovement 0
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, RocketHideout_B1F_Frlg_EventScript_Rival_text_3M
	goto_if_eq VAR_RESULT, FEMALE, RocketHideout_B1F_Frlg_EventScript_Rival_text_3F
	delay 10
	applymovement LOCALID_OAKS_LAB_RIVAL, Common_Movement_FaceUp
	applymovement LOCALID_OAKS_LAB_RIVAL, Common_Movement_FaceDown
	waitmovement 0
	delay 10
	applymovement LOCALID_OAKS_LAB_RIVAL, Common_Movement_FaceRight
	applymovement LOCALID_OAKS_LAB_RIVAL, Common_Movement_FaceRight
	waitmovement 0
	msgbox RocketHideout_B1F_Frlg_Text_Rival_3, MSGBOX_NPC
	msgbox RocketHideout_B1F_Frlg_Text_Ronnie_3, MSGBOX_NPC
	playse SE_BREAKABLE_DOOR
	applymovement LOCALID_OAKS_LAB_RIVAL, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox RocketHideout_B1F_Frlg_Text_Rival_4, MSGBOX_NPC
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, RocketHideout_B1F_Frlg_EventScript_Rival_text_4M
	goto_if_eq VAR_RESULT, FEMALE, RocketHideout_B1F_Frlg_EventScript_Rival_text_4F
	applymovement LOCALID_OAKS_LAB_RIVAL, Common_Movement_FaceUp
	waitmovement 0
	msgbox RocketHideout_B1F_Frlg_Text_Ronnie_5, MSGBOX_NPC
	msgbox RocketHideout_B1F_Frlg_Text_Ronnie_6, MSGBOX_NPC
	applymovement LOCALID_OAKS_LAB_RIVAL, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_OAKS_LAB_RIVAL, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_OAKS_LAB_RIVAL, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox RocketHideout_B1F_Frlg_Text_Ronnie_7, MSGBOX_NPC
	applymovement LOCALID_OAKS_LAB_RIVAL, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement LOCALID_OAKS_LAB_RIVAL, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_OAKS_LAB_RIVAL, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox RocketHideout_B1F_Frlg_Text_Ronnie_8, MSGBOX_NPC
	applymovement LOCALID_OAKS_LAB_RIVAL, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox RocketHideout_B1F_Frlg_Text_Rival_5, MSGBOX_NPC
	applymovement LOCALID_OAKS_LAB_RIVAL, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox RocketHideout_B1F_Frlg_Text_Ronnie_9, MSGBOX_NPC
	applymovement LOCALID_OAKS_LAB_RIVAL, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_OAKS_LAB_RIVAL, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox RocketHideout_B1F_Frlg_Text_Rival_6, MSGBOX_NPC
	applymovement LOCALID_OAKS_LAB_RIVAL, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	releaseall
	end

RocketHideout_B1F_Frlg_EventScript_Rival_text_3M::
	msgbox RocketHideout_B1F_Frlg_Text_Ronnie_2M, MSGBOX_NPC
	end

RocketHideout_B1F_Frlg_EventScript_Rival_text_3F::
	msgbox RocketHideout_B1F_Frlg_Text_Ronnie_2F, MSGBOX_NPC
	end

RocketHideout_B1F_Frlg_EventScript_Rival_text_4M::
	msgbox RocketHideout_B1F_Frlg_Text_Ronnie_4M, MSGBOX_NPC
	end

RocketHideout_B1F_Frlg_EventScript_Rival_text_4F::
	msgbox RocketHideout_B1F_Frlg_Text_Ronnie_4F, MSGBOX_NPC
	end

RocketHideout_B1F_Frlg_EventScript_Player_mov_ronnie_1::
    playse SE_PIN
	applymovement LOCALID_OAKS_LAB_RIVAL, Common_Movement_ExclamationMark
	applymovement LOCALID_OAKS_LAB_RIVAL, RocketHideout_B1F_Frlg_Movement_Player_mov_ronnie_1
	waitmovement 0
	end

RocketHideout_B1F_Frlg_EventScript_Player_mov_ronnie_2::
    playse SE_PIN
	applymovement LOCALID_OAKS_LAB_RIVAL, Common_Movement_ExclamationMark
	applymovement LOCALID_OAKS_LAB_RIVAL, RocketHideout_B1F_Frlg_Movement_Player_mov_ronnie_2
	waitmovement 0
    playse SE_PIN
	applymovement LOCALID_OAKS_LAB_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	end

RocketHideout_B1F_Frlg_Movement_Player_mov_ronnie_1::
    emote_exclamation_mark
    face_right
	step_end

RocketHideout_B1F_Frlg_Movement_Player_mov_ronnie_2::
    walk_down
    walk_left
    face_right
	step_end

RocketHideout_B1F_Frlg_Movement_ronnie_1::
    walk_left
    walk_left
    walk_left
    walk_left
	step_end

RocketHideout_B1F_Frlg_Text_Rival:
	.string "Hola, {PLAYER}, si buscas al cientifico,\n"
	.string "esta ahi abajo.$"

RocketHideout_B1F_Frlg_Text_Rival_2:
	.string "Bien, ¡ya tienes Vuelo!\p"
	.string "Entonces, busquemos a un idiota\n"
	.string "y robemos su Pokémon Volador.$"

RocketHideout_B1F_Frlg_Text_Ronnie_1:
	.string "¡Ey, esperen!$"

RocketHideout_B1F_Frlg_Text_Ronnie_2M:
	.string "Ustedes son {PLAYER} y Roxy, ¿no?$"

RocketHideout_B1F_Frlg_Text_Ronnie_2F:
	.string "Ustedes son {PLAYER} y Rocky, ¿no?$"

RocketHideout_B1F_Frlg_Text_Ronnie_3:
	.string "Digamos que… tengo buen oido…\p"
	.string "Cuando se inscriberon, escuche sus\n"
	.string "Nombres en la fila.\p"
	.string "Aproposito, ¡Parecian una pareja\n"
	.string "inscribiendose juntos!$"

RocketHideout_B1F_Frlg_Text_Ronnie_4M:
	.string "¡Tranquila, jaja, solo bromeaba!\p"
	.string "¿Asi que, Van a robar sus primeros\n"
	.string "Pokémon? ¡Genial!$"

RocketHideout_B1F_Frlg_Text_Ronnie_4F:
	.string "Eh… ¡Tranquilo, solo bromeaba!\p"
	.string "¿Asi que, Van a robar sus primeros\n"
	.string "Pokémon? ¡Genial!$"

RocketHideout_B1F_Frlg_Text_Ronnie_5:
	.string "Aunque, no parecen ser personas\n"
	.string "quienes saldrian y decidirian ser un\l"
	.string "delincuente profesional.\p"
	.string "¡De seguro que ni saben robar ni un$"
	.string "caramelo a un Niño!$"
	.string "Pero no se lo tomen a mal, yo puedo$"
	.string "hecharles una mano.$"

RocketHideout_B1F_Frlg_Text_Ronnie_6:
	.string "Solo… Esperen aquí.$"

RocketHideout_B1F_Frlg_Text_Ronnie_7:
	.string "Una MO02, ¡por favor!\n"
	.string "¡Y que sea rápido!$"

RocketHideout_B1F_Frlg_Text_Ronnie_8:
	.string "Aproposito, me llamo Ronnie.$"

RocketHideout_B1F_Frlg_Text_Ronnie_9:
	.string "¡Bien, vamos a robarnos algunos\n"
	.string "Pokémon! ¡Vámonos!$"

RocketHideout_B1F_Frlg_Text_Rival_3:
	.string "Eh…\n"
	.string "¿y tu como sabes nuestros nombres?$"

RocketHideout_B1F_Frlg_Text_Rival_4:
	.string "¡Oye! ¡Solo somos amigos de la infancia!$"

RocketHideout_B1F_Frlg_Text_Rival_5:
	.string "Un gusto… Ronnie.$"

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

RocketHideout_B1F_Frlg_Text_Rival_6:
	.string "Bueno… ¡te veo arriba\n"
	.string "{PLAYER}!$"

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

RocketHideout_B1F_Frlg_Movement_Ronnie_2::
    face_up
	delay_8
    face_left
	step_end
