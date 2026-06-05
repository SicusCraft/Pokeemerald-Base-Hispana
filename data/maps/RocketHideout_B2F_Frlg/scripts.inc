RocketHideout_B2F_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RocketHideout_B2F_Frlg_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RocketHideout_B2F_Frlg_OnFrame
	.byte 0

RocketHideout_B2F_Frlg_OnTransition:
	setrespawn HEAL_LOCATION_CELADON_CITY
	call Common_EventScript_SetupRivalGfxId
	end

RocketHideout_B2F_Frlg_OnFrame::
	map_script_2 VAR_MAP_SCENE_GUARIDA_ROCKET_INTRO, 0, RocketHideout_B2F_Frlg_Intro
	.2byte 0

RocketHideout_B2F_Frlg_EventScript_Trigger_1::
	lock
	setspeaker SP_NAME_PETREL
	msgbox RocketHideout_B2F_Frlg_Text_A_donde_vas, MSGBOX_AUTOCLOSE
	applymovement LOCALID_PLAYER, RocketHideout_B2F_Frlg_Movement_PlayerMov_1
	release
	end

RocketHideout_B2F_Frlg_EventScript_RattataInicial::
	lock
	goto_if_set FLAG_RATTATA_OBTENIDO, RocketHideout_B2F_Frlg_EventScript_Caja
	faceplayer
	applymovement LOCALID_GRUNT_1, RocketHideout_B2F_Frlg_Movement_RivalMov_2
	showmonpic SPECIES_RATTATA, 3, 3
	playmoncry SPECIES_RATTATA, CRY_MODE_NORMAL
	msgbox RocketHideout_B2F_Frlg_Text_Rattata, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RocketHideout_B2F_Frlg_EventScript_RattataElegido
	goto_if_eq VAR_RESULT, NO, RocketHideout_B2F_Frlg_EventScript_RattataNoElegido
	release
	end

RocketHideout_B2F_Frlg_EventScript_RattataElegido::
	hidemonpic
	msgbox RocketHideout_B2F_Frlg_Text_Quieres_a_Rattata, MSGBOX_AUTOCLOSE
	givemon SPECIES_RATTATA, 5
	message RocketHideout_B2F_Frlg_Text_RattataObtenido
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	waitfanfare
	waitmessage
	bufferspeciesname STR_VAR_1, SPECIES_RATTATA
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RocketHideout_B2F_Frlg_EventScript_Muevete
	call RocketHideout_B2F_Frlg_EventScript_Nombre
	end

RocketHideout_B2F_Frlg_EventScript_RattataNoElegido::
	hidemonpic
	msgbox RocketHideout_B2F_Frlg_Text_No_Quieres_a_Rattata, MSGBOX_AUTOCLOSE
	givemon SPECIES_RATTATA, 5
	message RocketHideout_B2F_Frlg_Text_RattataObtenido
	waitmessage
	playfanfare MUS_RG_OBTAIN_KEY_ITEM
	waitfanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, RocketHideout_B2F_Frlg_EventScript_Nombre
	goto_if_eq VAR_RESULT, NO, RocketHideout_B2F_Frlg_EventScript_Muevete
	end

RocketHideout_B2F_Frlg_EventScript_Muevete::
	applymovement LOCALID_PETREL, RocketHideout_B2F_Frlg_Movement_PetrelMov_1
	waitmovement 0
    setspeaker SP_NAME_PETREL
	msgbox RocketHideout_B2F_Frlg_Text_Muevete, MSGBOX_AUTOCLOSE
	setflag FLAG_RATTATA_OBTENIDO
	setflag FLAG_HIDE_RIVAL_IN_ROCKET_HIDEOUT
	setflag FLAG_SYS_POKEMON_GET
	removeobject LOCALID_GRUNT_1
	setvar VAR_MAP_SCENE_GUARIDA_ROCKET_BLOQUEOS, 1
	releaseall
	end

RocketHideout_B2F_Frlg_EventScript_Caja::
	applymovement LOCALID_PETREL, Common_Movement_FaceUp
	waitmovement 0
    setspeaker SP_NAME_PETREL
	msgbox RocketHideout_B2F_Frlg_Text_Caja_1, MSGBOX_AUTOCLOSE
	applymovement LOCALID_PETREL, Common_Movement_FaceDown
	waitmovement 0
	end

RocketHideout_B2F_Frlg_EventScript_Nombre::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	goto RocketHideout_B2F_Frlg_EventScript_Muevete
	end

RocketHideout_B2F_Frlg_EventScript_Recluta_1::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, RocketHideout_B2F_Frlg_EventScript_Recluta_1M
	goto_if_eq VAR_RESULT, FEMALE, RocketHideout_B2F_Frlg_EventScript_Recluta_1F
	end

RocketHideout_B2F_Frlg_EventScript_Recluta_1Rattata::
	goto_if_set FLAG_RATTATA_OBTENIDO, RocketHideout_B2F_Frlg_EventScript_Recluta_1
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, RocketHideout_B2F_Frlg_EventScript_Recluta_1MRattata
	goto_if_eq VAR_RESULT, FEMALE, RocketHideout_B2F_Frlg_EventScript_Recluta_1FRattata
	end

RocketHideout_B2F_Frlg_EventScript_Recluta_1MRattata::
	msgbox RocketHideout_B2F_Frlg_Text_Recluta_1MRattata, MSGBOX_NPC
	end

RocketHideout_B2F_Frlg_EventScript_Recluta_1M::
	msgbox RocketHideout_B2F_Frlg_Text_Recluta_1M, MSGBOX_NPC
	end

RocketHideout_B2F_Frlg_EventScript_Recluta_1FRattata::
	msgbox RocketHideout_B2F_Frlg_Text_Recluta_1FRattata, MSGBOX_NPC
	end

RocketHideout_B2F_Frlg_EventScript_Recluta_1F::
	msgbox RocketHideout_B2F_Frlg_Text_Recluta_1F, MSGBOX_NPC
	end

RocketHideout_B2F_Frlg_EventScript_Recluta_2::
	msgbox RocketHideout_B2F_Frlg_Text_Recluta_2, MSGBOX_NPC
	end

RocketHideout_B2F_Frlg_Intro:
	turnobject LOCALID_PLAYER, DIR_NORTH
	lockall
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, RocketHideout_B2F_Frlg_Movement_CameraMov_1
	waitmovement 0
	applymovement LOCALID_PETREL, RocketHideout_B2F_Frlg_Movement_PetrelMov_1
	waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
    setspeaker SP_NAME_PETREL
	msgbox RocketHideout_B2F_Frlg_Text_Petrel_1, MSGBOX_AUTOCLOSE
	applymovement LOCALID_PETREL, RocketHideout_B2F_Frlg_Movement_PetrelMov_2
	waitmovement 0
    setspeaker SP_NAME_PETREL
	msgbox RocketHideout_B2F_Frlg_Text_Petrel_2, MSGBOX_AUTOCLOSE
	applymovement LOCALID_PETREL, Common_Movement_FaceUp
	waitmovement 0
    setspeaker SP_NAME_PETREL
	msgbox RocketHideout_B2F_Frlg_Text_Petrel_3, MSGBOX_AUTOCLOSE
	applymovement LOCALID_PETREL, Common_Movement_FaceDown
	waitmovement 0
    setspeaker SP_NAME_PETREL
	msgbox RocketHideout_B2F_Frlg_Text_Petrel_4, MSGBOX_AUTOCLOSE
	applymovement LOCALID_PETREL, Common_Movement_FaceRight
	waitmovement 0
    setspeaker SP_NAME_PETREL
	msgbox RocketHideout_B2F_Frlg_Text_Petrel_5, MSGBOX_AUTOCLOSE
	applymovement LOCALID_PETREL, Common_Movement_FaceDown
	waitmovement 0
    setspeaker SP_NAME_PETREL
	msgbox RocketHideout_B2F_Frlg_Text_Petrel_6, MSGBOX_AUTOCLOSE
	playse SE_BREAKABLE_DOOR
	applymovement LOCALID_PETREL, RocketHideout_B2F_Frlg_Movement_PetrelMov_1
	waitmovement 0
    setspeaker SP_NAME_PETREL
	msgbox RocketHideout_B2F_Frlg_Text_Petrel_7, MSGBOX_AUTOCLOSE
	applymovement LOCALID_CAMERA, RocketHideout_B2F_Frlg_Movement_CameraMov_2
	waitmovement 0
	applymovement LOCALID_GRUNT_1, RocketHideout_B2F_Frlg_Movement_ReclutaMov_1
	applymovement LOCALID_PLAYER, RocketHideout_B2F_Frlg_Movement_ReclutaMov_1
	applymovement LOCALID_GRUNT_2, RocketHideout_B2F_Frlg_Movement_ReclutaMov_1
	applymovement LOCALID_GRUNT_3, RocketHideout_B2F_Frlg_Movement_ReclutaMov_1
	applymovement LOCALID_GRUNT_4, RocketHideout_B2F_Frlg_Movement_ReclutaMov_1
	applymovement LOCALID_GRUNT_5, RocketHideout_B2F_Frlg_Movement_ReclutaMov_1
	applymovement LOCALID_GRUNT_6, RocketHideout_B2F_Frlg_Movement_ReclutaMov_1
	applymovement LOCALID_GRUNT_7, RocketHideout_B2F_Frlg_Movement_ReclutaMov_1
	applymovement LOCALID_GRUNT_8, RocketHideout_B2F_Frlg_Movement_ReclutaMov_1
	applymovement LOCALID_GRUNT_9, RocketHideout_B2F_Frlg_Movement_ReclutaMov_1
	applymovement LOCALID_GRUNT_10, RocketHideout_B2F_Frlg_Movement_ReclutaMov_1
	applymovement LOCALID_GRUNT_11, RocketHideout_B2F_Frlg_Movement_ReclutaMov_1
	applymovement LOCALID_GRUNT_12, RocketHideout_B2F_Frlg_Movement_ReclutaMov_1
	applymovement LOCALID_GRUNT_13, RocketHideout_B2F_Frlg_Movement_ReclutaMov_1
	applymovement LOCALID_GRUNT_14, RocketHideout_B2F_Frlg_Movement_ReclutaMov_1
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox RocketHideout_B2F_Frlg_Text_Reclutas, MSGBOX_AUTOCLOSE
	applymovement LOCALID_CAMERA, RocketHideout_B2F_Frlg_Movement_CameraMov_3
	waitmovement 0
	textcolor NPC_TEXT_COLOR_MALE
    setspeaker SP_NAME_PETREL
	msgbox RocketHideout_B2F_Frlg_Text_Petrel_8, MSGBOX_AUTOCLOSE
	applymovement LOCALID_CAMERA, RocketHideout_B2F_Frlg_Movement_CameraMov_4
	waitmovement 0
	special RemoveCameraObject
	playse SE_LEDGE
	applymovement LOCALID_GRUNT_1, RocketHideout_B2F_Frlg_Movement_RivalMov_1
	waitmovement 0
	setobjectxyperm LOCALID_GRUNT_1, 2, 5
	setobjectmovementtype LOCALID_GRUNT_1, MOVEMENT_TYPE_FACE_UP
	playmoncry SPECIES_RATTATA, CRY_MODE_NORMAL
	waitmoncry
	delay 0x10
	applymovement LOCALID_PETREL, RocketHideout_B2F_Frlg_Movement_PetrelMov_1
	waitmovement 0
    setspeaker SP_NAME_PETREL
	msgbox RocketHideout_B2F_Frlg_Text_Petrel_9, MSGBOX_AUTOCLOSE
	setflag FLAG_SYS_B_DASH
	setvar VAR_MAP_SCENE_GUARIDA_ROCKET_INTRO, 1
	release
	end

RocketHideout_B2F_Frlg_Text_Petrel_1:
	.string "¡Muy bien novatos! ¡Presten atención\n"
	.string "que esto lo diré solo una vez!\p"
	.string "¡Oficialmente ya son Reclutas del\n"
	.string "Team Rocket!\p"
	.string "Pero aún no se den palmaditas en la\n"
	.string "espalda.\p"
	.string "¡Hasta que no me demuestren lo\n"
	.string "contrario, ustedes son solo un\l"
	.string "montón de niñatos para mí!$"

RocketHideout_B2F_Frlg_Text_Petrel_2:
	.string "Cambiando de tema, pronto van a\n"
	.string "recibir su primera misión\p"
	.string "Pero antes de eso, tenemos que\n"
	.string "hacer un par de cosas…$"

RocketHideout_B2F_Frlg_Text_Petrel_3:
	.string "Detrás mío están las cajas donde\n"
	.string "encontraran su primer Pokémon.$"

RocketHideout_B2F_Frlg_Text_Petrel_4:
	.string "Comenzando con los reclutas desde\n"
	.string "arriba a la izquierda, quiero\l"
	.string "que se acerquen para recibir a su\l"
	.string "Pequeño roedor.$"

RocketHideout_B2F_Frlg_Text_Petrel_5:
	.string "Luego deben dirigirse al último\n"
	.string "piso subiendo las escaleras a mi\l"
	.string "derecha.\p"
	.string "Ahí, uno de nuestros científicos\n"
	.string "les entregaran una MO, la cual\l"
	.string "es Vuelo.$"

RocketHideout_B2F_Frlg_Text_Petrel_6:
	.string "Una vez obtenida la MO, intenten\n"
	.string "robarse algún Pokémon volador…\p"
	.string "¡Enséñenle Vuelo a ese Pokémon usando\n"
	.string "la MO, y luego vayan volando hacia\l"
	.string "el Mt. Moon tan pronto sea\l"
	.string "posible!\p"
	.string "¡En ese lugar recibirán más\n"
	.string "instrucciones!$"

RocketHideout_B2F_Frlg_Text_Petrel_7:
	.string "¡¿QUEDO CLARO?!$"

RocketHideout_B2F_Frlg_Text_Reclutas:
	.string "¡SÍ, SEÑOR!$"

RocketHideout_B2F_Frlg_Text_Petrel_8:
	.string "¡Bien, comencemos!$"

RocketHideout_B2F_Frlg_Text_Petrel_9:
	.string "¡El que sigue!$"

RocketHideout_B2F_Frlg_Text_Rattata:
	.string "¿Quieres elegir a Rattata como tu\n"
	.string "Pokémon inicial?$"

RocketHideout_B2F_Frlg_Text_Quieres_a_Rattata:
	.string "Este Pokémon no se ve muy\n"
	.string "energético…$"

RocketHideout_B2F_Frlg_Text_No_Quieres_a_Rattata:
	.string "-De todas formas no tengo otra\n"
	.string "elección-$"

RocketHideout_B2F_Frlg_Text_RattataObtenido:
	.string "Has recibido a Rattata.$"

RocketHideout_B2F_Frlg_Text_Muevete:
	.string "¡El siguiente!, ¡Muevete!$"

RocketHideout_B2F_Frlg_Text_Caja_1:
	.string "¡Oye! ¡Solo un Rattata por\n"
	.string "Soldado! ¿Me oyes?$"

RocketHideout_B2F_Frlg_Text_Recluta_1MRattata:
	.string "¿Puedo saber a donde vas\n"
	.string "recluta? ¡Ve y busca a tu\l"
	.string "roedor!$"
	.string "¡Haz lo que te dicen!$"

RocketHideout_B2F_Frlg_Text_Recluta_1M:
	.string "¿Puedo saber a donde vas\n"
	.string "recluta? ¡Debes reportarte\l"
	.string "arriba!$"
	.string "¡Haz lo que te dicen!$"

RocketHideout_B2F_Frlg_Text_Recluta_1F:
	.string "Mira señorita, no puedo\n"
	.string "dejarte pasar, debes\l"
	.string "reportarte arriba.$"

RocketHideout_B2F_Frlg_Text_Recluta_1FRattata:
	.string "Quieta ahi señorita, ve y\n"
	.string "busca a tu roedor.$"

RocketHideout_B2F_Frlg_Text_Recluta_2:
	.string "Escalera equivocada Colega.$"

RocketHideout_B2F_Frlg_Text_A_donde_vas:
	.string "¡Ey, Recluta! ¡Vuelve aquí$"
	.string "y recoge a tu Rattata!$"

RocketHideout_B2F_Frlg_Movement_CameraMov_1::
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RocketHideout_B2F_Frlg_Movement_PetrelMov_1::
	walk_in_place_down
	step_end

RocketHideout_B2F_Frlg_Movement_PetrelMov_2::
	walk_up
	delay_8
	face_down
	delay_8
	step_end

RocketHideout_B2F_Frlg_Movement_CameraMov_2::
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

RocketHideout_B2F_Frlg_Movement_CameraMov_3::
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

RocketHideout_B2F_Frlg_Movement_CameraMov_4::
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RocketHideout_B2F_Frlg_Movement_RivalMov_1::
	jump_in_place_up
	delay_16
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_16
	step_end

RocketHideout_B2F_Frlg_Movement_RivalMov_2::
	walk_down
	walk_right
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	delay_16
	step_end

RocketHideout_B2F_Frlg_Movement_ReclutaMov_1::
	walk_in_place_up
	step_end

RocketHideout_B2F_Frlg_Movement_PlayerMov_1::
	walk_down
	step_end
