@ Super Fire Red: Hoenn after the events of Emerald.
@ Runs once, when the player first arrives at Slateport from Kanto. Every Emerald story
@ event counts as already done: story vars get their final value, Team Aqua/Magma and
@ the NPCs of the old story scenes are hidden, and the story flags are set.

SFR_EventScript_InitHoennWorld::
	goto_if_set FLAG_SFR_HOENN_WORLD_INIT, SFR_EventScript_InitHoennWorldDone
	setvar VAR_LITTLEROOT_INTRO_STATE, 7
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 5
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 5
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4
	setvar VAR_BIRCH_LAB_STATE, 5
	setvar VAR_ROUTE101_STATE, 3
	setvar VAR_OLDALE_TOWN_STATE, 1
	setvar VAR_OLDALE_RIVAL_STATE, 2
	setvar VAR_ROUTE110_STATE, 1
	setvar VAR_SLATEPORT_CITY_STATE, 2
	setvar VAR_SLATEPORT_HARBOR_STATE, 2
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	setvar VAR_PETALBURG_CITY_STATE, 5
	setvar VAR_PETALBURG_GYM_STATE, 6
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	setvar VAR_PETALBURG_WOODS_STATE, 1
	setvar VAR_RUSTURF_TUNNEL_STATE, 3
	setvar VAR_DEVON_CORP_3F_STATE, 1
	setvar VAR_BRINEY_HOUSE_STATE, 1
	setvar VAR_ROUTE116_STATE, 2
	setvar VAR_ROUTE118_STATE, 1
	setvar VAR_ROUTE119_STATE, 1
	setvar VAR_WEATHER_INSTITUTE_STATE, 2
	setvar VAR_MT_PYRE_STATE, 3
	setvar VAR_JAGGED_PASS_STATE, 2
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	setvar VAR_LAVARIDGE_TOWN_STATE, 2
	setvar VAR_MOSSDEEP_CITY_STATE, 3
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 3
	setvar VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 3
	setvar VAR_SEAFLOOR_CAVERN_STATE, 1
	setvar VAR_SOOTOPOLIS_CITY_STATE, 6
	setvar VAR_ROUTE121_STATE, 1
	setvar VAR_ROUTE128_STATE, 2
	setvar VAR_METEOR_FALLS_STATE, 1
	setvar VAR_HAS_TALKED_TO_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, 1
	setvar VAR_VICTORY_ROAD_1F_STATE, 3
	setflag FLAG_RESCUED_BIRCH
	setflag FLAG_MET_RIVAL_MOM
	setflag FLAG_BIRCH_AIDE_MET
	setflag FLAG_MET_TEAM_AQUA_HARBOR
	setflag FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT
	setflag FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE
	setflag FLAG_DEFEATED_MAGMA_SPACE_CENTER
	setflag FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN
	setflag FLAG_DEVON_GOODS_STOLEN
	setflag FLAG_RECOVERED_DEVON_GOODS
	setflag FLAG_RETURNED_DEVON_GOODS
	setflag FLAG_DELIVERED_DEVON_GOODS
	setflag FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE
	setflag FLAG_INTERACTED_WITH_DEVON_EMPLOYEE_GOODS_STOLEN
	setflag FLAG_DELIVERED_STEVEN_LETTER
	setflag FLAG_DEFEATED_GRUNT_SPACE_CENTER_1F
	setflag FLAG_INTERACTED_WITH_STEVEN_SPACE_CENTER
	setflag FLAG_MET_ARCHIE_METEOR_FALLS
	setflag FLAG_RETURNED_RED_OR_BLUE_ORB
	setflag FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN
	setflag FLAG_MET_ARCHIE_SOOTOPOLIS
	setflag FLAG_MET_MAXIE_SOOTOPOLIS
	setflag FLAG_WALLACE_GOES_TO_SKY_PILLAR
	setflag FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setflag FLAG_DEFEATED_RIVAL_ROUTE103
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	setflag FLAG_MET_RIVAL_RUSTBORO
	setflag FLAG_MET_RIVAL_LILYCOVE
	setflag FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE
	setflag FLAG_RIVAL_LEFT_FOR_ROUTE103
	setflag FLAG_DEFEATED_WALLY_MAUVILLE
	setflag FLAG_THANKED_FOR_PLAYING_WITH_WALLY
	setflag FLAG_WALLY_SPEECH
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_1_BLOCKING_ENTRANCE
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_2_BLOCKING_ENTRANCE
	setflag FLAG_HIDE_AQUA_HIDEOUT_B1F_ELECTRODE_1
	setflag FLAG_HIDE_AQUA_HIDEOUT_B1F_ELECTRODE_2
	setflag FLAG_HIDE_AQUA_HIDEOUT_B2F_SUBMARINE_SHADOW
	setflag FLAG_HIDE_AQUA_HIDEOUT_GRUNTS
	setflag FLAG_HIDE_CAVE_OF_ORIGIN_B1F_WALLACE
	setflag FLAG_HIDE_CHAMPIONS_ROOM_BIRCH
	setflag FLAG_HIDE_CHAMPIONS_ROOM_RIVAL
	setflag FLAG_HIDE_GRANITE_CAVE_STEVEN
	setflag FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD
	setflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL
	setflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL_ON_BIKE
	setflag FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS
	setflag FLAG_HIDE_LILYCOVE_CITY_RIVAL
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_BEDROOM_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_1
	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_2
	setflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
	setflag FLAG_HIDE_MAGMA_HIDEOUT_4F_GROUDON
	setflag FLAG_HIDE_MAGMA_HIDEOUT_4F_GROUDON_ASLEEP
	setflag FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	setflag FLAG_HIDE_MAUVILLE_CITY_WALLY
	setflag FLAG_HIDE_MAUVILLE_CITY_WALLYS_UNCLE
	setflag FLAG_HIDE_METEOR_FALLS_TEAM_AQUA
	setflag FLAG_HIDE_METEOR_FALLS_TEAM_MAGMA
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_MAGMA_NOTE
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_MAXIE
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	setflag FLAG_HIDE_PETALBURG_CITY_WALLY
	setflag FLAG_HIDE_PETALBURG_CITY_WALLYS_DAD
	setflag FLAG_HIDE_PETALBURG_GYM_WALLY
	setflag FLAG_HIDE_PETALBURG_GYM_WALLYS_DAD
	setflag FLAG_HIDE_PETALBURG_WOODS_AQUA_GRUNT
	setflag FLAG_HIDE_PETALBURG_WOODS_DEVON_EMPLOYEE
	setflag FLAG_HIDE_PLAYERS_HOUSE_DAD
	setflag FLAG_HIDE_ROUTE_101_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	setflag FLAG_HIDE_ROUTE_101_ZIGZAGOON
	setflag FLAG_HIDE_ROUTE_103_BIRCH
	setflag FLAG_HIDE_ROUTE_103_RIVAL
	setflag FLAG_HIDE_ROUTE_104_RIVAL
	setflag FLAG_HIDE_ROUTE_110_BIRCH
	setflag FLAG_HIDE_ROUTE_110_RIVAL
	setflag FLAG_HIDE_ROUTE_110_RIVAL_ON_BIKE
	setflag FLAG_HIDE_ROUTE_110_TEAM_AQUA
	setflag FLAG_HIDE_ROUTE_112_TEAM_MAGMA
	setflag FLAG_HIDE_ROUTE_116_DEVON_EMPLOYEE
	setflag FLAG_HIDE_ROUTE_118_STEVEN
	setflag FLAG_HIDE_ROUTE_119_RIVAL
	setflag FLAG_HIDE_ROUTE_119_RIVAL_ON_BIKE
	setflag FLAG_HIDE_ROUTE_119_TEAM_AQUA
	setflag FLAG_HIDE_ROUTE_120_STEVEN
	setflag FLAG_HIDE_ROUTE_121_TEAM_AQUA_GRUNTS
	setflag FLAG_HIDE_ROUTE_128_ARCHIE
	setflag FLAG_HIDE_ROUTE_128_MAXIE
	setflag FLAG_HIDE_ROUTE_128_STEVEN
	setflag FLAG_HIDE_RUSTBORO_CITY_AQUA_GRUNT
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setflag FLAG_HIDE_RUSTURF_TUNNEL_AQUA_GRUNT
	setflag FLAG_HIDE_RUSTURF_TUNNEL_PEEKO
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_AQUA_GRUNTS
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ENTRANCE_AQUA_GRUNT
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_ARCHIE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_KYOGRE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_KYOGRE_ASLEEP
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAGMA_GRUNTS
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAXIE
	setflag FLAG_HIDE_SKY_PILLAR_TOP_RAYQUAZA_STILL
	setflag FLAG_HIDE_SKY_PILLAR_WALLACE
	setflag FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN
	setflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT
	setflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE
	setflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_AQUA_GRUNT_1
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_AQUA_GRUNT_2
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_ARCHIE
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_CAPTAIN_STERN
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_FAMILIAR_AQUA_GRUNT
	setflag FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_GROUDON
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_KYOGRE
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_RAYQUAZA
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	setflag FLAG_HIDE_UNDERWATER_SEA_FLOOR_CAVERN_STOLEN_SUBMARINE
	setflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY
	setflag FLAG_HIDE_VICTORY_ROAD_EXIT_WALLY
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_AQUA_GRUNT_M
	@ the S.S. Tidal sails from the start; Peeko is back home with Mr. Briney
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SS_TIDAL
	clearflag FLAG_HIDE_LILYCOVE_HARBOR_SSTIDAL
	clearflag FLAG_HIDE_LILYCOVE_HARBOR_FERRY_ATTENDANT
	clearflag FLAG_HIDE_LILYCOVE_HARBOR_FERRY_SAILOR
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_MR_BRINEY_SAILING_INTRO
	setvar VAR_BRINEY_LOCATION, 1
	@ Wally lives with his uncle in Verdanturf
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLYS_UNCLE
	@ Captain Stern works at the harbor again
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO
	@ Rayquaza sleeps at the top of Sky Pillar
	clearflag FLAG_HIDE_SKY_PILLAR_TOP_RAYQUAZA
	setflag FLAG_SFR_HOENN_WORLD_INIT
SFR_EventScript_InitHoennWorldDone::
	return
@ ---------------------------------------------------------------------------
@ Oak's lab: right after the National Pokedex upgrade, Oak sends the player to Hoenn.
SFR_EventScript_OakAuthorizesHoennTrip::
	msgbox SFR_Text_OakFriendInHoenn, MSGBOX_DEFAULT
	setflag FLAG_SFR_HOENN_TRIP_AUTHORIZED
	return

SFR_Text_OakFriendInHoenn:
	.string "OAK: Oh, {PLAYER}, one more thing.\p"
	.string "Far to the southwest of KANTO lies\n"
	.string "a region called HOENN.\p"
	.string "An old friend of mine, PROF. BIRCH,\n"
	.string "studies POKéMON habitats there.\p"
	.string "He could use the help of a TRAINER\n"
	.string "with a National POKéDEX like yours.\p"
	.string "Your S.S. TICKET is still valid.\n"
	.string "I've arranged everything with the\l"
	.string "port in VERMILION CITY.\p"
	.string "Show your ticket to the sailor by\n"
	.string "the dock and he'll take you aboard\l"
	.string "the S.S. TIDAL to SLATEPORT CITY.\p"
	.string "I'm sure HOENN's POKéMON will\n"
	.string "fascinate you. Off you go!$"

@ ---------------------------------------------------------------------------
@ Vermilion City: sailor of the S.S. Tidal, Kanto -> Slateport
SFR_EventScript_VermilionHoennSailor::
	lock
	faceplayer
	goto_if_unset FLAG_SFR_HOENN_TRIP_AUTHORIZED, SFR_EventScript_VermilionHoennSailorNotYet
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, SFR_EventScript_VermilionHoennSailorNotYet
	msgbox SFR_Text_VermilionSailorBoardToSlateport, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SFR_EventScript_VermilionHoennSailorDeclined
	msgbox SFR_Text_VermilionSailorAllAboard, MSGBOX_DEFAULT
	closemessage
	call_if_lt VAR_SFR_HOENN_STATE, 1, SFR_EventScript_SetSailingToHoenn
	playse SE_SHIP
	fadescreenspeed FADE_TO_BLACK, 12
	delay 60
	warp MAP_SLATEPORT_CITY_HARBOR, 8, 11
	waitstate
	release
	end

SFR_EventScript_SetSailingToHoenn::
	setvar VAR_SFR_HOENN_STATE, 1
	return

SFR_EventScript_VermilionHoennSailorNotYet::
	msgbox SFR_Text_VermilionSailorNeedPermission, MSGBOX_DEFAULT
	release
	end

SFR_EventScript_VermilionHoennSailorDeclined::
	msgbox SFR_Text_VermilionSailorComeBackAnytime, MSGBOX_DEFAULT
	release
	end

SFR_Text_VermilionSailorNeedPermission:
	.string "The S.S. TIDAL sails between\n"
	.string "VERMILION and SLATEPORT, in HOENN.\p"
	.string "Only passengers with a special\n"
	.string "permit may board, I'm afraid.$"

SFR_Text_VermilionSailorBoardToSlateport:
	.string "Ah, PROF. OAK told us about you!\p"
	.string "The S.S. TIDAL is bound for\n"
	.string "SLATEPORT CITY in HOENN.\p"
	.string "Would you like to board?$"

SFR_Text_VermilionSailorAllAboard:
	.string "All aboard!$"

SFR_Text_VermilionSailorComeBackAnytime:
	.string "Come back whenever you're ready\n"
	.string "to set sail.$"

@ ---------------------------------------------------------------------------
@ VAR_SFR_HOENN_STATE
@ 0: In Kanto
@ 1: Sailing to Hoenn (arrival scene pending at Slateport Harbor)
@ 2: Met Brendan, Birch's welcome pending
@ 3: Choosing a starter in Birch's lab
@ 4: Got the starter, Brendan waits by the lab door
@ 5: Got the Pokénav and DexNav

@ Slateport Harbor: arrival from Vermilion
SFR_EventScript_SlateportHarborArrival::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	playse SE_PIN
	applymovement LOCALID_SLATEPORT_HARBOR_SFR_BRENDAN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SLATEPORT_HARBOR_SFR_BRENDAN, Common_Movement_Delay48
	waitmovement 0
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
	applymovement LOCALID_SLATEPORT_HARBOR_SFR_BRENDAN, SFR_Movement_HarborBrendanApproach
	waitmovement 0
	msgbox SFR_Text_HarborBrendanWelcome, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SFR_HOENN_STATE, 2
	setflag FLAG_SFR_HIDE_SLATEPORT_HARBOR_BRENDAN
	clearflag FLAG_SFR_HIDE_BIRCHS_LAB_BRENDAN
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_SLATEPORT_HARBOR_SFR_BRENDAN
	playse SE_M_FLY
	delay 40
	warpsilent MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 11
	waitstate
	releaseall
	end

SFR_Movement_HarborBrendanApproach:
	walk_up
	walk_up
	step_end

@ Slateport Harbor: ferry back to Kanto
SFR_EventScript_SlateportFerryToVermilion::
	msgbox SFR_Text_VermilionItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseNewDestination
	call SlateportCity_Harbor_EventScript_BoardFerry
	warp MAP_VERMILION_CITY, 25, 32
	waitstate
	release
	end

@ Birch's lab -------------------------------------------------------------
SFR_EventScript_BirchsLabFaceNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

SFR_EventScript_BirchsLabWelcome::
	lockall
	applymovement LOCALID_PLAYER, SFR_Movement_PlayerWalkToBirch
	waitmovement 0
	msgbox SFR_Text_BirchWelcome, MSGBOX_DEFAULT
	applymovement LOCALID_BIRCHS_LAB_SFR_BRENDAN, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SFR_Text_BirchLabBrendanAfterWelcome, MSGBOX_DEFAULT
	setvar VAR_SFR_HOENN_STATE, 3
	releaseall
	end

SFR_Movement_PlayerWalkToBirch:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SFR_EventScript_BirchsLabBirchChooseStarter::
	msgbox SFR_Text_BirchChooseStarter, MSGBOX_DEFAULT
	release
	end

SFR_EventScript_BirchsLabTreeckoBall::
	setvar VAR_TEMP_2, SPECIES_TREECKO
	goto SFR_EventScript_BirchsLabStarterBall
	end

SFR_EventScript_BirchsLabTorchicBall::
	setvar VAR_TEMP_2, SPECIES_TORCHIC
	goto SFR_EventScript_BirchsLabStarterBall
	end

SFR_EventScript_BirchsLabMudkipBall::
	setvar VAR_TEMP_2, SPECIES_MUDKIP
	goto SFR_EventScript_BirchsLabStarterBall
	end

SFR_EventScript_BirchsLabStarterBall::
	lock
	goto_if_set FLAG_SFR_RECEIVED_HOENN_STARTER, SFR_EventScript_BirchsLabLeaveOthers
	copyvar VAR_0x8004, VAR_TEMP_2
	bufferspeciesname STR_VAR_1, VAR_0x8004
	showmonpic VAR_0x8004, 10, 3
	msgbox SFR_Text_BirchYoullTakeStarter, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SFR_EventScript_BirchsLabTakeYourTime
	setvar VAR_TEMP_TRANSFERRED_SPECIES, 0
	copyvar VAR_TEMP_TRANSFERRED_SPECIES, VAR_0x8004
	givemon VAR_0x8004, 45, ITEM_EVERSTONE
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, SFR_EventScript_BirchsLabStarterToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, SFR_EventScript_BirchsLabStarterToPC
	hidemonpic
	goto Common_EventScript_NoMoreRoomForPokemon
	end

SFR_EventScript_BirchsLabStarterToParty::
	call SFR_EventScript_BirchsLabReceivedStarter
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SFR_EventScript_BirchsLabAfterStarter
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto SFR_EventScript_BirchsLabAfterStarter
	end

SFR_EventScript_BirchsLabStarterToPC::
	call SFR_EventScript_BirchsLabReceivedStarter
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SFR_EventScript_BirchsLabStarterTransferred
	call Common_EventScript_NameReceivedBoxMon
SFR_EventScript_BirchsLabStarterTransferred::
	call Common_EventScript_TransferredToPC
	goto SFR_EventScript_BirchsLabAfterStarter
	end

SFR_EventScript_BirchsLabReceivedStarter::
	copyvar VAR_SFR_HOENN_STARTER, VAR_0x8004
	setflag FLAG_SFR_RECEIVED_HOENN_STARTER
	removeobject VAR_LAST_TALKED
	hidemonpic
	playfanfare MUS_OBTAIN_ITEM
	message SFR_Text_ReceivedHoennStarter
	waitmessage
	waitfanfare
	return

SFR_EventScript_BirchsLabAfterStarter::
	setvar VAR_SFR_HOENN_STATE, 4
	applymovement LOCALID_BIRCHS_LAB_BIRCH, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SFR_Text_BirchAfterStarter, MSGBOX_DEFAULT
	closemessage
	msgbox SFR_Text_BirchLabBrendanWaitByDoor, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BIRCHS_LAB_SFR_BRENDAN, SFR_Movement_BrendanToDoor
	waitmovement 0
	setobjectxyperm LOCALID_BIRCHS_LAB_SFR_BRENDAN, 5, 10
	setobjectmovementtype LOCALID_BIRCHS_LAB_SFR_BRENDAN, MOVEMENT_TYPE_FACE_RIGHT
	release
	end

SFR_Movement_BrendanToDoor:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

SFR_EventScript_BirchsLabLeaveOthers::
	msgbox SFR_Text_BirchLeaveOthers, MSGBOX_DEFAULT
	release
	end

SFR_EventScript_BirchsLabTakeYourTime::
	hidemonpic
	msgbox SFR_Text_BirchTakeYourTime, MSGBOX_DEFAULT
	release
	end

SFR_EventScript_BirchsLabBrendan::
	lock
	faceplayer
	goto_if_ge VAR_SFR_HOENN_STATE, 4, SFR_EventScript_BirchsLabBrendanGoAhead
	msgbox SFR_Text_BirchLabBrendanAfterWelcome, MSGBOX_DEFAULT
	release
	end

SFR_EventScript_BirchsLabBrendanGoAhead::
	msgbox SFR_Text_BirchLabBrendanWaitByDoor, MSGBOX_DEFAULT
	release
	end

SFR_EventScript_BirchsLabPokenavTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto SFR_EventScript_BirchsLabPokenav
	end

SFR_EventScript_BirchsLabPokenavTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto SFR_EventScript_BirchsLabPokenav
	end

SFR_EventScript_BirchsLabPokenav::
	applymovement LOCALID_BIRCHS_LAB_SFR_BRENDAN, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	call_if_eq VAR_0x8008, 1, SFR_EventScript_BirchsLabBrendanStepCloser
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox SFR_Text_BrendanGivesPokenav, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message SFR_Text_ReceivedPokenav
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_HAS_MATCH_CALL
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
	msgbox SFR_Text_BrendanGivesDexNav, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message SFR_Text_ReceivedDexNav
	waitmessage
	waitfanfare
	setflag FLAG_SFR_DEXNAV_GET
	setflag FLAG_SFR_RECEIVED_POKENAV
	msgbox SFR_Text_BrendanSeeYouOnRoute103, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, SFR_EventScript_BirchsLabBrendanLeave0
	call_if_eq VAR_0x8008, 1, SFR_EventScript_BirchsLabBrendanLeave1
	playse SE_EXIT
	removeobject LOCALID_BIRCHS_LAB_SFR_BRENDAN
	setflag FLAG_SFR_HIDE_BIRCHS_LAB_BRENDAN
	setvar VAR_SFR_HOENN_STATE, 5
	releaseall
	end

SFR_EventScript_BirchsLabBrendanStepCloser::
	applymovement LOCALID_BIRCHS_LAB_SFR_BRENDAN, Common_Movement_WalkRight
	waitmovement 0
	return

SFR_EventScript_BirchsLabBrendanLeave0::
	applymovement LOCALID_BIRCHS_LAB_SFR_BRENDAN, SFR_Movement_BrendanLeaveFromLeft
	waitmovement 0
	return

SFR_EventScript_BirchsLabBrendanLeave1::
	applymovement LOCALID_BIRCHS_LAB_SFR_BRENDAN, SFR_Movement_BrendanLeaveFromCenter
	waitmovement 0
	return

SFR_Movement_BrendanLeaveFromLeft:
	walk_down
	step_end

SFR_Movement_BrendanLeaveFromCenter:
	walk_down
	walk_down
	step_end

@ Texts --------------------------------------------------------------------
SFR_Text_VermilionItIs:
	.string "VERMILION CITY in KANTO it is, then!$"

SFR_Text_HarborBrendanWelcome:
	.string "BRENDAN: Hey! You must be {PLAYER}!\n"
	.string "The TRAINER from KANTO, right?\p"
	.string "I'm BRENDAN. My dad is PROF. BIRCH.\p"
	.string "PROF. OAK phoned him and said you\n"
	.string "were coming to see HOENN.\p"
	.string "Dad wants to meet you at his lab in\n"
	.string "LITTLEROOT TOWN. It's a long way from\l"
	.string "here, so I'll fly you there!\p"
	.string "Come on, let's go!$"

SFR_Text_BirchWelcome:
	.string "PROF. BIRCH: Welcome to HOENN,\n"
	.string "{PLAYER}! I'm PROF. BIRCH.\p"
	.string "My old friend PROF. OAK told me\n"
	.string "all about you.\p"
	.string "Beating the KANTO LEAGUE!\n"
	.string "That's really something!\p"
	.string "Here in HOENN, things have finally\n"
	.string "calmed down after some big trouble.\p"
	.string "It's the perfect time to explore!\p"
	.string "To get you started, I'd like you\n"
	.string "to have a POKéMON from HOENN.\p"
	.string "The three POKé BALLS on that table\n"
	.string "hold TREECKO, TORCHIC and MUDKIP.\p"
	.string "They've been raised well, so they're\n"
	.string "quite strong already.\p"
	.string "Go on, choose the one you like!$"

SFR_Text_BirchLabBrendanAfterWelcome:
	.string "BRENDAN: I already have my partner\n"
	.string "from Dad. Pick whichever you like!$"

SFR_Text_BirchChooseStarter:
	.string "PROF. BIRCH: Go on, pick one of the\n"
	.string "POKé BALLS on the table!$"

SFR_Text_BirchYoullTakeStarter:
	.string "PROF. BIRCH: So, you'd like\n"
	.string "the {STR_VAR_1}?$"

SFR_Text_BirchTakeYourTime:
	.string "PROF. BIRCH: Take your time.\n"
	.string "They're all wonderful POKéMON.$"

SFR_Text_ReceivedHoennStarter:
	.string "{PLAYER} received the {STR_VAR_1}\n"
	.string "from PROF. BIRCH!$"

SFR_Text_BirchLeaveOthers:
	.string "PROF. BIRCH: The others are staying\n"
	.string "here with me, I'm afraid.$"

SFR_Text_BirchAfterStarter:
	.string "PROF. BIRCH: That POKéMON is holding\n"
	.string "an EVERSTONE.\p"
	.string "It won't evolve while it holds the\n"
	.string "stone. When you feel your bond is\l"
	.string "strong enough, just take it away.\p"
	.string "HOENN has eight GYMS, and you can\n"
	.string "challenge them in any order you like.\p"
	.string "Beat all eight and you can take on\n"
	.string "the POKéMON LEAGUE!$"

SFR_Text_BirchLabBrendanWaitByDoor:
	.string "BRENDAN: Before you go, I've got\n"
	.string "something for you. Don't run off!$"

SFR_Text_BrendanGivesPokenav:
	.string "BRENDAN: Here! This is a POKéNAV.\n"
	.string "Everyone in HOENN carries one.$"

SFR_Text_ReceivedPokenav:
	.string "{PLAYER} received the POKéNAV!$"

SFR_Text_BrendanGivesDexNav:
	.string "BRENDAN: And this is the DEXNAV!\p"
	.string "It shows which POKéMON live in the\n"
	.string "area, even ones hiding in the grass.$"

SFR_Text_ReceivedDexNav:
	.string "{PLAYER} received the DEXNAV!$"

SFR_Text_BrendanSeeYouOnRoute103:
	.string "BRENDAN: I'm heading to ROUTE 103,\n"
	.string "past OLDALE TOWN.\p"
	.string "Come find me there. I want to see\n"
	.string "how strong a KANTO CHAMPION really is!$"

@ Littleroot houses: Brendan's house is the Birch family's, May's house is Norman's.
SFR_EventScript_SetupBrendansHouse1F::
	call_if_set FLAG_SFR_HOENN_GAME_CLEAR, SFR_EventScript_ShowBrendanAtHome
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_1
	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_2
	setflag FLAG_HIDE_PLAYERS_HOUSE_DAD
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_SIBLING
	goto_if_set FLAG_SFR_HOENN_GAME_CLEAR, SFR_EventScript_SetupBrendansHouse1FEnd
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN
SFR_EventScript_SetupBrendansHouse1FEnd::
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_MOM
	end

SFR_EventScript_ShowBrendanAtHome::
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN
	return

SFR_EventScript_SetupMaysHouse1F::
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MOM
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 6, 5
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_1
	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_2
	setflag FLAG_HIDE_PLAYERS_HOUSE_DAD
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MAY
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_MOM
	end

SFR_EventScript_SetupRivalHouse2F::
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_BEDROOM_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
	call SecretBase_EventScript_SetDecorationFlags
	setvar VAR_SECRET_BASE_INITIALIZED, 1
	end

SFR_EventScript_MrsBirch::
	lock
	faceplayer
	goto_if_ge VAR_SFR_HOENN_STATE, 5, SFR_EventScript_MrsBirchLater
	msgbox SFR_Text_MrsBirchFirst, MSGBOX_DEFAULT
	release
	end

SFR_EventScript_MrsBirchLater::
	msgbox SFR_Text_MrsBirchLater, MSGBOX_DEFAULT
	release
	end

SFR_EventScript_MaysMom::
	lock
	faceplayer
	goto_if_set FLAG_SFR_HOENN_GAME_CLEAR, SFR_EventScript_MaysMomAfterLeague
	msgbox SFR_Text_MaysMom, MSGBOX_DEFAULT
	release
	end

SFR_EventScript_MaysMomAfterLeague::
	msgbox SFR_Text_MaysMomAfterLeague, MSGBOX_DEFAULT
	release
	end

SFR_Text_NormansHouseSign:
	.string "NORMAN'S HOUSE$"

SFR_Text_MrsBirchFirst:
	.string "Oh, hello! You must be the TRAINER\n"
	.string "from KANTO my husband mentioned.\p"
	.string "I'm BRENDAN's mother. Please go and\n"
	.string "see the PROFESSOR at his lab!$"

SFR_Text_MrsBirchLater:
	.string "BRENDAN is always out somewhere,\n"
	.string "helping his father with fieldwork.\p"
	.string "He's grown so much. He even says\n"
	.string "he's going to beat the CHAMPION!$"

SFR_Text_MaysMom:
	.string "Hello! I'm MAY's mother.\p"
	.string "My husband NORMAN is the GYM LEADER\n"
	.string "in PETALBURG CITY.\p"
	.string "And MAY… She became the CHAMPION\n"
	.string "of HOENN! I'm so proud of her.\p"
	.string "She's always at the POKéMON LEAGUE\n"
	.string "these days, waiting for challengers.$"

SFR_Text_MaysMomAfterLeague:
	.string "MAY called and told me all about\n"
	.string "your battle!\p"
	.string "She said she's never had so much\n"
	.string "fun losing. Thank you, dear!$"

@ ---------------------------------------------------------------------------
@ Sootopolis Gym: Wallace also hands over HM07 Waterfall (needed for Victory Road)
SFR_EventScript_WallaceGiveWaterfall::
	checkitem ITEM_HM_WATERFALL
	goto_if_eq VAR_RESULT, TRUE, SFR_EventScript_WallaceGiveWaterfallDone
	msgbox SFR_Text_WallaceTakeWaterfall, MSGBOX_DEFAULT
	giveitem ITEM_HM_WATERFALL
	setflag FLAG_RECEIVED_HM_WATERFALL
	msgbox SFR_Text_WallaceExplainWaterfall, MSGBOX_DEFAULT
SFR_EventScript_WallaceGiveWaterfallDone::
	return

SFR_Text_WallaceTakeWaterfall:
	.string "WALLACE: And one more thing.\n"
	.string "You'll need this on the way to\l"
	.string "the POKéMON LEAGUE.$"

SFR_Text_WallaceExplainWaterfall:
	.string "WALLACE: That HM contains WATERFALL.\p"
	.string "It lets your POKéMON climb up\n"
	.string "walls of cascading water.$"

@ ---------------------------------------------------------------------------
@ Pokémon League: May, the Champion
SFR_Text_MayChampionIntro:
	.string "MAY: {PLAYER}! I knew you'd make it\n"
	.string "all the way here!\p"
	.string "Dad told me all about your battle\n"
	.string "in PETALBURG.\p"
	.string "When I first set out, I was just a\n"
	.string "girl from LITTLEROOT TOWN.\p"
	.string "Since then I've traveled all over\n"
	.string "HOENN, faced the worst trouble this\l"
	.string "region has ever seen…\p"
	.string "And I became the CHAMPION!\p"
	.string "You beat the KANTO LEAGUE, right?\n"
	.string "Then this is a battle between\l"
	.string "two CHAMPIONS!\p"
	.string "My POKéMON and I won't hold back.\n"
	.string "Here I come!$"

SFR_Text_MayChampionDefeat:
	.string "That was amazing…\n"
	.string "You really are the real deal!$"

SFR_Text_MayChampionPostBattle:
	.string "MAY: …I lost.\p"
	.string "But you know what? I'm not even\n"
	.string "upset. That was the most fun I've\l"
	.string "had in a battle in ages!\p"
	.string "{PLAYER}, you're the new CHAMPION\n"
	.string "of the HOENN LEAGUE!$"

SFR_Text_ChampionsRoomBrendanArrives:
	.string "BRENDAN: {PLAYER}! Did you…\p"
	.string "MAY, you lost?!$"

SFR_Text_ChampionsRoomBrendanYouWon:
	.string "BRENDAN: Wow… You actually beat\n"
	.string "MAY!\p"
	.string "I knew you were strong ever since\n"
	.string "that first battle on ROUTE 103!$"

SFR_Text_ChampionsRoomBirchCongratulations:
	.string "PROF. BIRCH: There you are!\p"
	.string "When BRENDAN ran off, I just had\n"
	.string "to come and see for myself.\p"
	.string "Congratulations, {PLAYER}!\p"
	.string "I can't wait to tell PROF. OAK!\n"
	.string "His friend from KANTO has become\l"
	.string "HOENN's new CHAMPION!$"

SFR_Text_MayComeWithMe:
	.string "MAY: {PLAYER}, please come with me.\n"
	.string "There's a place I want to show you.$"

SFR_Text_ChampionsRoomBrendanGoOn:
	.string "BRENDAN: Go on, {PLAYER}!\n"
	.string "We'll wait for you outside.$"

SFR_Text_HallOfFameMayHonor:
	.string "MAY: This room…\p"
	.string "This is where the POKéMON LEAGUE\n"
	.string "honors its CHAMPIONS and the POKéMON\l"
	.string "that battled alongside them.$"

SFR_Text_HallOfFameMayRecord:
	.string "MAY: Come on, let's record your name\n"
	.string "and the names of your partners!$"

@ ---------------------------------------------------------------------------
@ VAR_RESULT = TRUE if the player has all eight Hoenn badges (FLAG_BADGE09_GET-FLAG_BADGE16_GET)
SFR_EventScript_CheckAllHoennBadges::
	setvar VAR_RESULT, FALSE
	goto_if_unset FLAG_BADGE09_GET, SFR_EventScript_CheckAllHoennBadgesDone
	goto_if_unset FLAG_BADGE10_GET, SFR_EventScript_CheckAllHoennBadgesDone
	goto_if_unset FLAG_BADGE11_GET, SFR_EventScript_CheckAllHoennBadgesDone
	goto_if_unset FLAG_BADGE12_GET, SFR_EventScript_CheckAllHoennBadgesDone
	goto_if_unset FLAG_BADGE13_GET, SFR_EventScript_CheckAllHoennBadgesDone
	goto_if_unset FLAG_BADGE14_GET, SFR_EventScript_CheckAllHoennBadgesDone
	goto_if_unset FLAG_BADGE15_GET, SFR_EventScript_CheckAllHoennBadgesDone
	goto_if_unset FLAG_BADGE16_GET, SFR_EventScript_CheckAllHoennBadgesDone
	setvar VAR_RESULT, TRUE
SFR_EventScript_CheckAllHoennBadgesDone::
	return

@ ---------------------------------------------------------------------------
@ Brendan: five optional battles. He shows up once the player has enough Hoenn badges,
@ and stays until beaten. Key items are handed over just for talking to him.

@ VAR_RESULT = number of Hoenn badges
SFR_EventScript_CountHoennBadges::
	setvar VAR_RESULT, 0
	call_if_set FLAG_BADGE09_GET, SFR_EventScript_AddOneToResult
	call_if_set FLAG_BADGE10_GET, SFR_EventScript_AddOneToResult
	call_if_set FLAG_BADGE11_GET, SFR_EventScript_AddOneToResult
	call_if_set FLAG_BADGE12_GET, SFR_EventScript_AddOneToResult
	call_if_set FLAG_BADGE13_GET, SFR_EventScript_AddOneToResult
	call_if_set FLAG_BADGE14_GET, SFR_EventScript_AddOneToResult
	call_if_set FLAG_BADGE15_GET, SFR_EventScript_AddOneToResult
	call_if_set FLAG_BADGE16_GET, SFR_EventScript_AddOneToResult
	return

SFR_EventScript_AddOneToResult::
	addvar VAR_RESULT, 1
	return

SFR_EventScript_SetupBrendanRoute103::
	setflag FLAG_HIDE_ROUTE_103_RIVAL
	goto_if_set FLAG_SFR_DEFEATED_BRENDAN_ROUTE103, SFR_EventScript_SetupBrendanRoute103Done
	call SFR_EventScript_CountHoennBadges
	goto_if_lt VAR_RESULT, 0, SFR_EventScript_SetupBrendanRoute103Done
	clearflag FLAG_HIDE_ROUTE_103_RIVAL
SFR_EventScript_SetupBrendanRoute103Done::
	return

SFR_EventScript_BrendanRoute103::
	lock
	faceplayer
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
	msgbox SFR_Text_BrendanRoute103Intro, MSGBOX_DEFAULT
	switch VAR_SFR_HOENN_STARTER
	case SPECIES_TREECKO, SFR_EventScript_BrendanRoute103Treecko
	case SPECIES_TORCHIC, SFR_EventScript_BrendanRoute103Torchic
	goto SFR_EventScript_BrendanRoute103Mudkip
	end

SFR_EventScript_BrendanRoute103Treecko::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TREECKO, SFR_Text_BrendanRoute103Defeat
	goto SFR_EventScript_BrendanRoute103Defeated
	end

SFR_EventScript_BrendanRoute103Torchic::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TORCHIC, SFR_Text_BrendanRoute103Defeat
	goto SFR_EventScript_BrendanRoute103Defeated
	end

SFR_EventScript_BrendanRoute103Mudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_MUDKIP, SFR_Text_BrendanRoute103Defeat
	goto SFR_EventScript_BrendanRoute103Defeated
	end

SFR_EventScript_BrendanRoute103Defeated::
	setflag FLAG_SFR_DEFEATED_BRENDAN_ROUTE103
	msgbox SFR_Text_BrendanRoute103PostBattle, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	setflag FLAG_HIDE_ROUTE_103_RIVAL
	fadescreen FADE_FROM_BLACK
	fadedefaultbgm
	release
	end

SFR_EventScript_SetupBrendanRoute110::
	setflag FLAG_HIDE_ROUTE_110_RIVAL
	goto_if_set FLAG_SFR_DEFEATED_BRENDAN_ROUTE110, SFR_EventScript_SetupBrendanRoute110Done
	call SFR_EventScript_CountHoennBadges
	goto_if_lt VAR_RESULT, 2, SFR_EventScript_SetupBrendanRoute110Done
	clearflag FLAG_HIDE_ROUTE_110_RIVAL
SFR_EventScript_SetupBrendanRoute110Done::
	return

SFR_EventScript_BrendanRoute110::
	lock
	faceplayer
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
	goto_if_set FLAG_RECEIVED_GO_GOGGLES, SFR_EventScript_BrendanRoute110Battle
	msgbox SFR_Text_BrendanRoute110Item, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
SFR_EventScript_BrendanRoute110Battle::
	msgbox SFR_Text_BrendanRoute110Intro, MSGBOX_DEFAULT
	switch VAR_SFR_HOENN_STARTER
	case SPECIES_TREECKO, SFR_EventScript_BrendanRoute110Treecko
	case SPECIES_TORCHIC, SFR_EventScript_BrendanRoute110Torchic
	goto SFR_EventScript_BrendanRoute110Mudkip
	end

SFR_EventScript_BrendanRoute110Treecko::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_TREECKO, SFR_Text_BrendanRoute110Defeat
	goto SFR_EventScript_BrendanRoute110Defeated
	end

SFR_EventScript_BrendanRoute110Torchic::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_TORCHIC, SFR_Text_BrendanRoute110Defeat
	goto SFR_EventScript_BrendanRoute110Defeated
	end

SFR_EventScript_BrendanRoute110Mudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_MUDKIP, SFR_Text_BrendanRoute110Defeat
	goto SFR_EventScript_BrendanRoute110Defeated
	end

SFR_EventScript_BrendanRoute110Defeated::
	setflag FLAG_SFR_DEFEATED_BRENDAN_ROUTE110
	msgbox SFR_Text_BrendanRoute110PostBattle, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	setflag FLAG_HIDE_ROUTE_110_RIVAL
	fadescreen FADE_FROM_BLACK
	fadedefaultbgm
	release
	end

SFR_EventScript_SetupBrendanRoute119::
	setflag FLAG_HIDE_ROUTE_119_RIVAL
	goto_if_set FLAG_SFR_DEFEATED_BRENDAN_ROUTE119, SFR_EventScript_SetupBrendanRoute119Done
	call SFR_EventScript_CountHoennBadges
	goto_if_lt VAR_RESULT, 4, SFR_EventScript_SetupBrendanRoute119Done
	clearflag FLAG_HIDE_ROUTE_119_RIVAL
SFR_EventScript_SetupBrendanRoute119Done::
	return

SFR_EventScript_BrendanRoute119::
	lock
	faceplayer
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
	goto_if_set FLAG_RECEIVED_DEVON_SCOPE, SFR_EventScript_BrendanRoute119Battle
	msgbox SFR_Text_BrendanRoute119Item, MSGBOX_DEFAULT
	giveitem ITEM_DEVON_SCOPE
	setflag FLAG_RECEIVED_DEVON_SCOPE
SFR_EventScript_BrendanRoute119Battle::
	msgbox SFR_Text_BrendanRoute119Intro, MSGBOX_DEFAULT
	switch VAR_SFR_HOENN_STARTER
	case SPECIES_TREECKO, SFR_EventScript_BrendanRoute119Treecko
	case SPECIES_TORCHIC, SFR_EventScript_BrendanRoute119Torchic
	goto SFR_EventScript_BrendanRoute119Mudkip
	end

SFR_EventScript_BrendanRoute119Treecko::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_TREECKO, SFR_Text_BrendanRoute119Defeat
	goto SFR_EventScript_BrendanRoute119Defeated
	end

SFR_EventScript_BrendanRoute119Torchic::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_TORCHIC, SFR_Text_BrendanRoute119Defeat
	goto SFR_EventScript_BrendanRoute119Defeated
	end

SFR_EventScript_BrendanRoute119Mudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_119_MUDKIP, SFR_Text_BrendanRoute119Defeat
	goto SFR_EventScript_BrendanRoute119Defeated
	end

SFR_EventScript_BrendanRoute119Defeated::
	setflag FLAG_SFR_DEFEATED_BRENDAN_ROUTE119
	msgbox SFR_Text_BrendanRoute119PostBattle, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	setflag FLAG_HIDE_ROUTE_119_RIVAL
	fadescreen FADE_FROM_BLACK
	fadedefaultbgm
	release
	end

SFR_EventScript_SetupBrendanLilycove::
	setflag FLAG_HIDE_LILYCOVE_CITY_RIVAL
	goto_if_set FLAG_SFR_DEFEATED_BRENDAN_LILYCOVE, SFR_EventScript_SetupBrendanLilycoveDone
	call SFR_EventScript_CountHoennBadges
	goto_if_lt VAR_RESULT, 6, SFR_EventScript_SetupBrendanLilycoveDone
	clearflag FLAG_HIDE_LILYCOVE_CITY_RIVAL
SFR_EventScript_SetupBrendanLilycoveDone::
	return

SFR_EventScript_BrendanLilycove::
	lock
	faceplayer
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
	msgbox SFR_Text_BrendanLilycoveIntro, MSGBOX_DEFAULT
	switch VAR_SFR_HOENN_STARTER
	case SPECIES_TREECKO, SFR_EventScript_BrendanLilycoveTreecko
	case SPECIES_TORCHIC, SFR_EventScript_BrendanLilycoveTorchic
	goto SFR_EventScript_BrendanLilycoveMudkip
	end

SFR_EventScript_BrendanLilycoveTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TREECKO, SFR_Text_BrendanLilycoveDefeat
	goto SFR_EventScript_BrendanLilycoveDefeated
	end

SFR_EventScript_BrendanLilycoveTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TORCHIC, SFR_Text_BrendanLilycoveDefeat
	goto SFR_EventScript_BrendanLilycoveDefeated
	end

SFR_EventScript_BrendanLilycoveMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_MUDKIP, SFR_Text_BrendanLilycoveDefeat
	goto SFR_EventScript_BrendanLilycoveDefeated
	end

SFR_EventScript_BrendanLilycoveDefeated::
	setflag FLAG_SFR_DEFEATED_BRENDAN_LILYCOVE
	msgbox SFR_Text_BrendanLilycovePostBattle, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	setflag FLAG_HIDE_LILYCOVE_CITY_RIVAL
	fadescreen FADE_FROM_BLACK
	fadedefaultbgm
	release
	end

SFR_EventScript_SetupBrendanVictoryRoad::
	setflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY
	goto_if_set FLAG_SFR_DEFEATED_BRENDAN_VICTORY_ROAD, SFR_EventScript_SetupBrendanVictoryRoadDone
	call SFR_EventScript_CountHoennBadges
	goto_if_lt VAR_RESULT, 8, SFR_EventScript_SetupBrendanVictoryRoadDone
	clearflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY
SFR_EventScript_SetupBrendanVictoryRoadDone::
	return

SFR_EventScript_BrendanVictoryRoad::
	lock
	faceplayer
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
	msgbox SFR_Text_BrendanVictoryRoadIntro, MSGBOX_DEFAULT
	switch VAR_SFR_HOENN_STARTER
	case SPECIES_TREECKO, SFR_EventScript_BrendanVictoryRoadTreecko
	case SPECIES_TORCHIC, SFR_EventScript_BrendanVictoryRoadTorchic
	goto SFR_EventScript_BrendanVictoryRoadMudkip
	end

SFR_EventScript_BrendanVictoryRoadTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TREECKO, SFR_Text_BrendanVictoryRoadDefeat
	goto SFR_EventScript_BrendanVictoryRoadDefeated
	end

SFR_EventScript_BrendanVictoryRoadTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_TORCHIC, SFR_Text_BrendanVictoryRoadDefeat
	goto SFR_EventScript_BrendanVictoryRoadDefeated
	end

SFR_EventScript_BrendanVictoryRoadMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_RUSTBORO_MUDKIP, SFR_Text_BrendanVictoryRoadDefeat
	goto SFR_EventScript_BrendanVictoryRoadDefeated
	end

SFR_EventScript_BrendanVictoryRoadDefeated::
	setflag FLAG_SFR_DEFEATED_BRENDAN_VICTORY_ROAD
	msgbox SFR_Text_BrendanVictoryRoadPostBattle, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	setflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY
	fadescreen FADE_FROM_BLACK
	fadedefaultbgm
	release
	end


SFR_Text_BrendanRoute103Intro:
	.string "BRENDAN: Hey, {PLAYER}! You came!\p"
	.string "I've been training here while I\n"
	.string "waited for you.\p"
	.string "Let's see how a TRAINER from KANTO\n"
	.string "battles!$"

SFR_Text_BrendanRoute103Defeat:
	.string "Whoa! So that's KANTO's strength!$"

SFR_Text_BrendanRoute103PostBattle:
	.string "BRENDAN: You're really something,\n"
	.string "{PLAYER}.\p"
	.string "I'm going to keep training and help\n"
	.string "Dad with his fieldwork.\p"
	.string "Next time, I'll be the one who wins!\n"
	.string "See you around!$"

SFR_Text_BrendanRoute110Item:
	.string "BRENDAN: {PLAYER}! You've got two\n"
	.string "HOENN BADGES already? Nice!\p"
	.string "Oh, before I forget. Here!\p"
	.string "There's a desert past MAUVILLE where\n"
	.string "sand flies everywhere.\p"
	.string "You'll need these to get through it.$"

SFR_Text_BrendanRoute110Intro:
	.string "BRENDAN: My POKéMON have gotten a lot\n"
	.string "stronger too. Let's battle!$"

SFR_Text_BrendanRoute110Defeat:
	.string "Aww, man! Not again!$"

SFR_Text_BrendanRoute110PostBattle:
	.string "BRENDAN: Those GO-GOGGLES protect\n"
	.string "your eyes from sandstorms.\p"
	.string "I'm off to MAUVILLE.\n"
	.string "Catch you later, {PLAYER}!$"

SFR_Text_BrendanRoute119Item:
	.string "BRENDAN: {PLAYER}! Four BADGES now?\n"
	.string "You're moving fast!\p"
	.string "Here, take this. STEVEN asked me to\n"
	.string "pass it on to a TRAINER who could\l"
	.string "use it.\p"
	.string "It's a DEVON SCOPE. It can reveal\n"
	.string "POKéMON that are invisible.\p"
	.string "There are some sneaky KECLEON\n"
	.string "around FORTREE CITY, you know.$"

SFR_Text_BrendanRoute119Intro:
	.string "BRENDAN: Now that that's done…\n"
	.string "Battle me, {PLAYER}!$"

SFR_Text_BrendanRoute119Defeat:
	.string "I thought I had you that time!$"

SFR_Text_BrendanRoute119PostBattle:
	.string "BRENDAN: The WEATHER INSTITUTE is\n"
	.string "around here. Dad says they study\l"
	.string "HOENN's weird weather.\p"
	.string "See you, {PLAYER}!$"

SFR_Text_BrendanLilycoveIntro:
	.string "BRENDAN: {PLAYER}! Six BADGES!\n"
	.string "You're almost ready for the LEAGUE.\p"
	.string "But first, you've got to get past me!$"

SFR_Text_BrendanLilycoveDefeat:
	.string "Seriously? You're too strong!$"

SFR_Text_BrendanLilycovePostBattle:
	.string "BRENDAN: MAY is waiting at the top.\n"
	.string "She's beaten me every single time.\p"
	.string "Maybe you're the one who can\n"
	.string "beat her, {PLAYER}.$"

SFR_Text_BrendanVictoryRoadIntro:
	.string "BRENDAN: I knew you'd come this way,\n"
	.string "{PLAYER}.\p"
	.string "Before you face MAY, I want one last\n"
	.string "battle. Everything I've got!$"

SFR_Text_BrendanVictoryRoadDefeat:
	.string "That's it… You're ready.$"

SFR_Text_BrendanVictoryRoadPostBattle:
	.string "BRENDAN: Go on, {PLAYER}.\n"
	.string "The POKéMON LEAGUE is just ahead.\p"
	.string "Show MAY what you've got!$"

@ ---------------------------------------------------------------------------
@ Archie in Shoal Cave: tells what happened, apologizes, gives HM08 Dive and battles
SFR_EventScript_ShoalCaveArchie::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, SFR_EventScript_ShoalCaveArchieBattle
	msgbox SFR_Text_ArchieStory, MSGBOX_DEFAULT
	giveitem ITEM_HM_DIVE
	setflag FLAG_RECEIVED_HM_DIVE
	msgbox SFR_Text_ArchieExplainDive, MSGBOX_DEFAULT
SFR_EventScript_ShoalCaveArchieBattle::
	msgbox SFR_Text_ArchieBattleIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ARCHIE, SFR_Text_ArchieDefeat
	msgbox SFR_Text_ArchiePostBattle, MSGBOX_DEFAULT
	giveitem ITEM_SHARPEDONITE
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	setflag FLAG_SFR_HIDE_SHOAL_CAVE_ARCHIE
	fadescreen FADE_FROM_BLACK
	release
	end

SFR_Text_ArchieStory:
	.string "Bwahahaha! A TRAINER, all the way\n"
	.string "down here?\p"
	.string "I'm ARCHIE. Once, I was the leader\n"
	.string "of TEAM AQUA.\p"
	.string "We wanted to expand the sea for the\n"
	.string "sake of all POKéMON.\p"
	.string "So we awakened KYOGRE…\n"
	.string "And it nearly drowned all of HOENN.\p"
	.string "TEAM MAGMA did the same with GROUDON.\n"
	.string "The rain and the sun went wild.\p"
	.string "In the end, RAYQUAZA came down from\n"
	.string "the sky and calmed them both.\p"
	.string "A young TRAINER named MAY stood up\n"
	.string "to us. She was right, and we were\l"
	.string "wrong.\p"
	.string "TEAM AQUA is no more. I've been\n"
	.string "living quietly by the sea since then.\p"
	.string "…I'm sorry for everything we put\n"
	.string "this region through.\p"
	.string "Take this. I won't be needing it to\n"
	.string "chase anything anymore.$"

SFR_Text_ArchieExplainDive:
	.string "That's DIVE. With it, your POKéMON\n"
	.string "can carry you under the waves.\p"
	.string "You'll need the BADGE from MOSSDEEP\n"
	.string "to use it, though.$"

SFR_Text_ArchieBattleIntro:
	.string "ARCHIE: But I'm still a man of the\n"
	.string "sea, and I can't let you leave\l"
	.string "without a battle!\p"
	.string "Show me what you've got!$"

SFR_Text_ArchieDefeat:
	.string "Bwahahaha! Like the tide,\n"
	.string "you just keep coming!$"

SFR_Text_ArchiePostBattle:
	.string "ARCHIE: You remind me of her.\p"
	.string "Here, take this stone too. My\n"
	.string "SHARPEDO won't need it anymore.$"

@ ---------------------------------------------------------------------------
@ Maxie at the top of Mt. Chimney: tells his side, apologizes and battles
SFR_EventScript_MtChimneyMaxie::
	lock
	faceplayer
	msgbox SFR_Text_MaxieStory, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, SFR_Text_MaxieDefeat
	msgbox SFR_Text_MaxiePostBattle, MSGBOX_DEFAULT
	giveitem ITEM_CAMERUPTITE
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	setflag FLAG_SFR_HIDE_MT_CHIMNEY_MAXIE
	fadescreen FADE_FROM_BLACK
	release
	end

SFR_Text_MaxieStory:
	.string "…You're not from HOENN, are you?\p"
	.string "I am MAXIE. I once led TEAM MAGMA.\p"
	.string "I believed humanity needed more land\n"
	.string "to prosper. So I woke GROUDON.\p"
	.string "Here, on this very mountain, we tried\n"
	.string "to use the METEORITE to make the\l"
	.string "volcano erupt.\p"
	.string "I told myself it was for everyone's\n"
	.string "sake. In truth, I had stopped\l"
	.string "listening to anyone but myself.\p"
	.string "The drought nearly destroyed the\n"
	.string "very people I meant to help.\p"
	.string "TEAM MAGMA has disbanded.\n"
	.string "I come here to remember my mistake.\p"
	.string "I am truly sorry.\p"
	.string "…Still, my POKéMON have never stopped\n"
	.string "believing in me.\p"
	.string "Will you battle us? I wish to see\n"
	.string "the strength of a TRAINER who has\l"
	.string "never strayed.$"

SFR_Text_MaxieDefeat:
	.string "I see… That is the strength of\n"
	.string "someone who never loses sight of\l"
	.string "what matters.$"

SFR_Text_MaxiePostBattle:
	.string "MAXIE: Thank you.\p"
	.string "I will keep working to make amends,\n"
	.string "one step at a time.\p"
	.string "Please, take this. Use it better\n"
	.string "than I did.$"

@ ---------------------------------------------------------------------------
@ Steven in Meteor Falls: optional battle, gives the Mega Ring when beaten
SFR_EventScript_MeteorFallsSteven::
	lock
	goto_if_set FLAG_DEFEATED_METEOR_FALLS_STEVEN, SFR_EventScript_MeteorFallsStevenDefeated
	waitse
	playse SE_PIN
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SFR_Text_StevenIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN, SFR_Text_StevenDefeat
	setflag FLAG_DEFEATED_METEOR_FALLS_STEVEN
	msgbox SFR_Text_StevenGiveMegaRing, MSGBOX_DEFAULT
	giveitem ITEM_MEGA_RING
	msgbox SFR_Text_StevenExplainMegaRing, MSGBOX_DEFAULT
	giveitem ITEM_METAGROSSITE
	release
	end

SFR_EventScript_MeteorFallsStevenDefeated::
	applymovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SFR_Text_StevenPostBattle, MSGBOX_DEFAULT
	release
	end

SFR_Text_StevenIntro:
	.string "STEVEN: Oh? A visitor, all the way\n"
	.string "back here?\p"
	.string "You must be the TRAINER from KANTO\n"
	.string "everyone's talking about.\p"
	.string "I'm STEVEN. I used to be the CHAMPION\n"
	.string "of HOENN, before WALLACE and MAY.\p"
	.string "These days I'm studying MEGA\n"
	.string "EVOLUTION and the stones behind it.\p"
	.string "If you can beat me, I'll give you\n"
	.string "something special. Ready?$"

SFR_Text_StevenDefeat:
	.string "Impressive. Truly impressive.$"

SFR_Text_StevenGiveMegaRing:
	.string "STEVEN: You've earned this.\n"
	.string "Take it.$"

SFR_Text_StevenExplainMegaRing:
	.string "STEVEN: That's a MEGA RING.\p"
	.string "When a POKéMON holds its MEGA STONE,\n"
	.string "the ring lets it MEGA EVOLVE during\l"
	.string "battle.\p"
	.string "MEGA STONES are hidden all over\n"
	.string "HOENN. Search well!\p"
	.string "And take this one as well.\n"
	.string "It's METAGROSS's stone.$"

SFR_Text_StevenPostBattle:
	.string "STEVEN: Have you found any MEGA\n"
	.string "STONES yet?\p"
	.string "The bond between you and your\n"
	.string "POKéMON is what makes them shine.$"

@ ---------------------------------------------------------------------------
@ Wally at his uncle's house in Verdanturf: optional battle
SFR_EventScript_VerdanturfWally::
	lock
	faceplayer
	call_if_set FLAG_SFR_HOENN_GAME_CLEAR, SFR_EventScript_WallyMysticTicket
	goto_if_set FLAG_SFR_DEFEATED_WALLY_VERDANTURF, SFR_EventScript_VerdanturfWallyDefeated
	msgbox SFR_Text_WallyIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SFR_EventScript_VerdanturfWallyDecline
	msgbox SFR_Text_WallyLetsGo, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_VR_1, SFR_Text_WallyDefeat
	setflag FLAG_SFR_DEFEATED_WALLY_VERDANTURF
	msgbox SFR_Text_WallyPostBattle, MSGBOX_DEFAULT
	release
	end

SFR_EventScript_VerdanturfWallyDecline::
	msgbox SFR_Text_WallyDecline, MSGBOX_DEFAULT
	release
	end

SFR_EventScript_VerdanturfWallyDefeated::
	msgbox SFR_Text_WallyPostBattle, MSGBOX_DEFAULT
	release
	end

SFR_Text_WallyIntro:
	.string "WALLY: Oh! Hello!\n"
	.string "I'm WALLY.\p"
	.string "The air here in VERDANTURF is so\n"
	.string "clean. It's helped me get healthy.\p"
	.string "I used to be too weak to even\n"
	.string "travel. Now I train every day with\l"
	.string "my POKéMON.\p"
	.string "MAY taught me how to catch my very\n"
	.string "first POKéMON, you know.\p"
	.string "Um… Would you battle with me?$"

SFR_Text_WallyLetsGo:
	.string "WALLY: Thank you!\n"
	.string "Here we go, GALLADE!$"

SFR_Text_WallyDecline:
	.string "WALLY: Oh… Okay. Come back when\n"
	.string "you have time!$"

SFR_Text_WallyDefeat:
	.string "I lost… But I'm not sad at all!$"

SFR_Text_WallyPostBattle:
	.string "WALLY: Battling makes me feel so\n"
	.string "alive!\p"
	.string "I'll keep training, so let's battle\n"
	.string "again someday!$"

@ ---------------------------------------------------------------------------
@ Juan, the new POKéMON CONTEST coordinator in Lilycove
SFR_EventScript_ContestLobbyJuan::
	msgbox SFR_Text_ContestLobbyJuan, MSGBOX_NPC
	end

SFR_Text_ContestLobbyJuan:
	.string "JUAN: Ah, welcome, my friend.\p"
	.string "I am JUAN. Once I led the GYM in\n"
	.string "SOOTOPOLIS, but I have passed it\l"
	.string "back to my pupil, WALLACE.\p"
	.string "Now I coordinate the POKéMON\n"
	.string "CONTESTS here in LILYCOVE.\p"
	.string "Beauty, elegance, the art of\n"
	.string "the stage… It is my true calling!\p"
	.string "Do show me your POKéMON's charms\n"
	.string "on stage sometime.$"

@ ---------------------------------------------------------------------------
@ Kanto Gym Leader rematches, after beating May (repeatable)
SFR_EventScript_BrockRematch::
	lock
	faceplayer
	msgbox SFR_Text_BrockRematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SFR_EventScript_KantoRematchDecline
	cleartrainerflag TRAINER_SFR_BROCK_REMATCH
	trainerbattle_no_intro TRAINER_SFR_BROCK_REMATCH, SFR_Text_BrockRematchDefeat
	msgbox SFR_Text_KantoRematchAfter, MSGBOX_DEFAULT
	release
	end

SFR_Text_BrockRematch:
	.string "BROCK: {PLAYER}! I heard you became\n"
	.string "the CHAMPION of HOENN too!\p"
	.string "My rock-hard POKéMON have trained\n"
	.string "with rocks from every region.\p"
	.string "Want to test them?$"

SFR_Text_BrockRematchDefeat:
	.string "BROCK: My defense crumbled…\n"
	.string "You're as solid as ever!$"

SFR_EventScript_MistyRematch::
	lock
	faceplayer
	msgbox SFR_Text_MistyRematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SFR_EventScript_KantoRematchDecline
	cleartrainerflag TRAINER_SFR_MISTY_REMATCH
	trainerbattle_no_intro TRAINER_SFR_MISTY_REMATCH, SFR_Text_MistyRematchDefeat
	msgbox SFR_Text_KantoRematchAfter, MSGBOX_DEFAULT
	release
	end

SFR_Text_MistyRematch:
	.string "MISTY: Oh, it's you! The double\n"
	.string "CHAMPION!\p"
	.string "I've been training WATER POKéMON\n"
	.string "from all over the world.\p"
	.string "Care for a splash?$"

SFR_Text_MistyRematchDefeat:
	.string "MISTY: You're still way too strong!$"

SFR_EventScript_LtSurgeRematch::
	lock
	faceplayer
	msgbox SFR_Text_LtSurgeRematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SFR_EventScript_KantoRematchDecline
	cleartrainerflag TRAINER_SFR_LT_SURGE_REMATCH
	trainerbattle_no_intro TRAINER_SFR_LT_SURGE_REMATCH, SFR_Text_LtSurgeRematchDefeat
	msgbox SFR_Text_KantoRematchAfter, MSGBOX_DEFAULT
	release
	end

SFR_Text_LtSurgeRematch:
	.string "LT. SURGE: Hey, kid! A CHAMPION of two\n"
	.string "regions, huh?\p"
	.string "My ELECTRIC troops are charged up\n"
	.string "like never before! Wanna rumble?$"

SFR_Text_LtSurgeRematchDefeat:
	.string "LT. SURGE: Whoa! You zapped us good!$"

SFR_EventScript_ErikaRematch::
	lock
	faceplayer
	msgbox SFR_Text_ErikaRematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SFR_EventScript_KantoRematchDecline
	cleartrainerflag TRAINER_SFR_ERIKA_REMATCH
	trainerbattle_no_intro TRAINER_SFR_ERIKA_REMATCH, SFR_Text_ErikaRematchDefeat
	msgbox SFR_Text_KantoRematchAfter, MSGBOX_DEFAULT
	release
	end

SFR_Text_ErikaRematch:
	.string "ERIKA: Oh, welcome back…\p"
	.string "My garden has grown with flowers\n"
	.string "from many lands.\p"
	.string "Would you care for a battle?$"

SFR_Text_ErikaRematchDefeat:
	.string "ERIKA: Oh my… Splendid, as always.$"

SFR_EventScript_KogaRematch::
	lock
	faceplayer
	msgbox SFR_Text_KogaRematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SFR_EventScript_KantoRematchDecline
	cleartrainerflag TRAINER_SFR_KOGA_REMATCH
	trainerbattle_no_intro TRAINER_SFR_KOGA_REMATCH, SFR_Text_KogaRematchDefeat
	msgbox SFR_Text_KantoRematchAfter, MSGBOX_DEFAULT
	release
	end

SFR_Text_KogaRematch:
	.string "KOGA: Fwahahaha! The CHAMPION returns!\p"
	.string "My POISON techniques have been\n"
	.string "refined across many regions.\p"
	.string "Will you face them?$"

SFR_Text_KogaRematchDefeat:
	.string "KOGA: Hmm… Your skill is genuine.$"

SFR_EventScript_SabrinaRematch::
	lock
	faceplayer
	msgbox SFR_Text_SabrinaRematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SFR_EventScript_KantoRematchDecline
	cleartrainerflag TRAINER_SFR_SABRINA_REMATCH
	trainerbattle_no_intro TRAINER_SFR_SABRINA_REMATCH, SFR_Text_SabrinaRematchDefeat
	msgbox SFR_Text_KantoRematchAfter, MSGBOX_DEFAULT
	release
	end

SFR_Text_SabrinaRematch:
	.string "SABRINA: I foresaw your return.\p"
	.string "My psychic powers have grown\n"
	.string "stronger still.\p"
	.string "Shall we battle?$"

SFR_Text_SabrinaRematchDefeat:
	.string "SABRINA: Even my visions could not\n"
	.string "foresee this outcome…$"

SFR_EventScript_BlaineRematch::
	lock
	faceplayer
	msgbox SFR_Text_BlaineRematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SFR_EventScript_KantoRematchDecline
	cleartrainerflag TRAINER_SFR_BLAINE_REMATCH
	trainerbattle_no_intro TRAINER_SFR_BLAINE_REMATCH, SFR_Text_BlaineRematchDefeat
	msgbox SFR_Text_KantoRematchAfter, MSGBOX_DEFAULT
	release
	end

SFR_Text_BlaineRematch:
	.string "BLAINE: Hah! The CHAMPION is back!\p"
	.string "My fiery POKéMON burn hotter than\n"
	.string "any volcano! Ready to get scorched?$"

SFR_Text_BlaineRematchDefeat:
	.string "BLAINE: I've burned out!\n"
	.string "You're a true flame, kid!$"

SFR_EventScript_KantoRematchDecline::
	msgbox SFR_Text_KantoRematchDecline, MSGBOX_DEFAULT
	release
	end

SFR_Text_KantoRematchDecline:
	.string "Come back whenever you're ready.$"

SFR_Text_KantoRematchAfter:
	.string "That was a great battle!\n"
	.string "Come challenge me again anytime.$"

@ ---------------------------------------------------------------------------
@ Prof. Oak after beating May: a Sinnoh starter, then the Shiny Charm for a complete Pokédex
SFR_EventScript_OakAfterHoenn::
	goto_if_unset FLAG_SFR_RECEIVED_SINNOH_STARTER, SFR_EventScript_OakSinnohStarter
	goto_if_set FLAG_SFR_RECEIVED_SHINY_CHARM, SFR_EventScript_OakAfterHoennDone
	special SfrHasCaughtAllObtainable
	goto_if_eq VAR_RESULT, FALSE, SFR_EventScript_OakAfterHoennDone
	msgbox SFR_Text_OakShinyCharm, MSGBOX_DEFAULT
	giveitem ITEM_SHINY_CHARM
	goto_if_eq VAR_RESULT, FALSE, SFR_EventScript_OakAfterHoennDone
	setflag FLAG_SFR_RECEIVED_SHINY_CHARM
	msgbox SFR_Text_OakExplainShinyCharm, MSGBOX_DEFAULT
SFR_EventScript_OakAfterHoennDone::
	return

SFR_EventScript_OakSinnohStarter::
	msgbox SFR_Text_OakSinnohStarterIntro, MSGBOX_DEFAULT
SFR_EventScript_OakSinnohStarterChoose::
	message SFR_Text_OakWhichSinnohStarter
	waitmessage
	dynmultipush SFR_Text_Turtwig, 0
	dynmultipush SFR_Text_Chimchar, 1
	dynmultipush SFR_Text_Piplup, 2
	dynmultichoice 20, 4, TRUE, 3, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, SFR_EventScript_OakTurtwig
	case 1, SFR_EventScript_OakChimchar
	setvar VAR_0x8004, SPECIES_PIPLUP
	goto SFR_EventScript_OakConfirmSinnohStarter
	end

SFR_EventScript_OakTurtwig::
	setvar VAR_0x8004, SPECIES_TURTWIG
	goto SFR_EventScript_OakConfirmSinnohStarter
	end

SFR_EventScript_OakChimchar::
	setvar VAR_0x8004, SPECIES_CHIMCHAR
	goto SFR_EventScript_OakConfirmSinnohStarter
	end

SFR_EventScript_OakConfirmSinnohStarter::
	bufferspeciesname STR_VAR_1, VAR_0x8004
	showmonpic VAR_0x8004, 10, 3
	msgbox SFR_Text_OakSoYouWant, MSGBOX_YESNO
	hidemonpic
	goto_if_eq VAR_RESULT, NO, SFR_EventScript_OakSinnohStarterChoose
	givemon VAR_0x8004, 45, ITEM_EVERSTONE
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, SFR_EventScript_OakSinnohStarterParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, SFR_EventScript_OakSinnohStarterPC
	msgbox gText_NoMoreRoomForPokemon, MSGBOX_DEFAULT
	release
	end

SFR_EventScript_OakSinnohStarterParty::
	call SFR_EventScript_OakReceivedSinnohStarter
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SFR_EventScript_OakSinnohStarterEnd
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto SFR_EventScript_OakSinnohStarterEnd
	end

SFR_EventScript_OakSinnohStarterPC::
	call SFR_EventScript_OakReceivedSinnohStarter
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SFR_EventScript_OakSinnohStarterSent
	call Common_EventScript_NameReceivedBoxMon
SFR_EventScript_OakSinnohStarterSent::
	call Common_EventScript_TransferredToPC
	goto SFR_EventScript_OakSinnohStarterEnd
	end

SFR_EventScript_OakReceivedSinnohStarter::
	setflag FLAG_SFR_RECEIVED_SINNOH_STARTER
	playfanfare MUS_OBTAIN_ITEM
	message SFR_Text_ReceivedSinnohStarter
	waitmessage
	waitfanfare
	return

SFR_EventScript_OakSinnohStarterEnd::
	msgbox SFR_Text_OakAfterSinnohStarter, MSGBOX_DEFAULT
	release
	end

SFR_Text_Turtwig:
	.string "TURTWIG$"
SFR_Text_Chimchar:
	.string "CHIMCHAR$"
SFR_Text_Piplup:
	.string "PIPLUP$"

SFR_Text_OakSinnohStarterIntro:
	.string "OAK: {PLAYER}! BIRCH called me!\n"
	.string "You're the CHAMPION of HOENN, too!\p"
	.string "Two regions… Remarkable!\p"
	.string "To celebrate, I have a gift for you.\p"
	.string "A friend of mine, PROF. ROWAN, sent\n"
	.string "me three POKéMON from SINNOH.\p"
	.string "Like the ones BIRCH gave you, they\n"
	.string "hold an EVERSTONE.$"

SFR_Text_OakWhichSinnohStarter:
	.string "Which one will you choose?$"

SFR_Text_OakSoYouWant:
	.string "OAK: So, you want {STR_VAR_1}?$"

SFR_Text_ReceivedSinnohStarter:
	.string "{PLAYER} received the {STR_VAR_1}\n"
	.string "from PROF. OAK!$"

SFR_Text_OakAfterSinnohStarter:
	.string "OAK: There are so many POKéMON out\n"
	.string "there, from every corner of the world.\p"
	.string "If you ever catch every POKéMON you\n"
	.string "can find, come and show me your\l"
	.string "POKéDEX!$"

SFR_Text_OakShinyCharm:
	.string "OAK: Ah, {PLAYER}! Let me see your\n"
	.string "POKéDEX…\p"
	.string "Incredible! You've caught every\n"
	.string "POKéMON there is to find!\p"
	.string "You've made my dream a reality.\n"
	.string "Please, take this!$"

SFR_Text_OakExplainShinyCharm:
	.string "OAK: That's the SHINY CHARM.\p"
	.string "It makes rare, differently colored\n"
	.string "POKéMON appear more often.$"

@ ---------------------------------------------------------------------------
@ New Regis: Regieleki (Ancient Tomb) and Regidrago (Desert Ruins) appear once the three
@ classic Regis are done; Regigigas (Island Cave) once all five are done.
SFR_EventScript_CheckClassicRegis::
	setvar VAR_RESULT, FALSE
	goto_if_unset FLAG_DEFEATED_REGIROCK, SFR_EventScript_CheckRegisDone
	goto_if_unset FLAG_DEFEATED_REGICE, SFR_EventScript_CheckRegisDone
	goto_if_unset FLAG_DEFEATED_REGISTEEL, SFR_EventScript_CheckRegisDone
	setvar VAR_RESULT, TRUE
SFR_EventScript_CheckRegisDone::
	return

SFR_EventScript_CheckAllFiveRegis::
	call SFR_EventScript_CheckClassicRegis
	goto_if_eq VAR_RESULT, FALSE, SFR_EventScript_CheckRegisDone
	setvar VAR_RESULT, FALSE
	goto_if_unset FLAG_SFR_DEFEATED_REGIELEKI, SFR_EventScript_CheckRegisDone
	goto_if_unset FLAG_SFR_DEFEATED_REGIDRAGO, SFR_EventScript_CheckRegisDone
	setvar VAR_RESULT, TRUE
	return

SFR_EventScript_SetupRegieleki::
	setflag FLAG_SFR_HIDE_REGIELEKI
	goto_if_set FLAG_SFR_DEFEATED_REGIELEKI, SFR_EventScript_CheckRegisDone
	call SFR_EventScript_CheckClassicRegis
	goto_if_eq VAR_RESULT, FALSE, SFR_EventScript_CheckRegisDone
	clearflag FLAG_SFR_HIDE_REGIELEKI
	return

SFR_EventScript_Regieleki::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGIELEKI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIELEKI, 72
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SFR_EventScript_RegielekiRan
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, SFR_EventScript_RegielekiRan
	setflag FLAG_SFR_DEFEATED_REGIELEKI
	setflag FLAG_SFR_HIDE_REGIELEKI
	goto Common_EventScript_RemoveStaticPokemon
	end

SFR_EventScript_RegielekiRan::
	setvar VAR_0x8004, SPECIES_REGIELEKI
	goto Common_EventScript_LegendaryFlewAway
	end

SFR_EventScript_SetupRegidrago::
	setflag FLAG_SFR_HIDE_REGIDRAGO
	goto_if_set FLAG_SFR_DEFEATED_REGIDRAGO, SFR_EventScript_CheckRegisDone
	call SFR_EventScript_CheckClassicRegis
	goto_if_eq VAR_RESULT, FALSE, SFR_EventScript_CheckRegisDone
	clearflag FLAG_SFR_HIDE_REGIDRAGO
	return

SFR_EventScript_Regidrago::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGIDRAGO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIDRAGO, 72
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SFR_EventScript_RegidragoRan
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, SFR_EventScript_RegidragoRan
	setflag FLAG_SFR_DEFEATED_REGIDRAGO
	setflag FLAG_SFR_HIDE_REGIDRAGO
	goto Common_EventScript_RemoveStaticPokemon
	end

SFR_EventScript_RegidragoRan::
	setvar VAR_0x8004, SPECIES_REGIDRAGO
	goto Common_EventScript_LegendaryFlewAway
	end

SFR_EventScript_SetupRegigigas::
	setflag FLAG_SFR_HIDE_REGIGIGAS
	goto_if_set FLAG_SFR_DEFEATED_REGIGIGAS, SFR_EventScript_CheckRegisDone
	call SFR_EventScript_CheckAllFiveRegis
	goto_if_eq VAR_RESULT, FALSE, SFR_EventScript_CheckRegisDone
	clearflag FLAG_SFR_HIDE_REGIGIGAS
	return

SFR_EventScript_Regigigas::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_REGIGIGAS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_REGIGIGAS, 75
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special StartRegiBattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SFR_EventScript_RegigigasRan
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, SFR_EventScript_RegigigasRan
	setflag FLAG_SFR_DEFEATED_REGIGIGAS
	setflag FLAG_SFR_HIDE_REGIGIGAS
	goto Common_EventScript_RemoveStaticPokemon
	end

SFR_EventScript_RegigigasRan::
	setvar VAR_0x8004, SPECIES_REGIGIGAS
	goto Common_EventScript_LegendaryFlewAway
	end


SFR_EventScript_StartLatiasRoaming::
	setvar VAR_ROAMER_POKEMON, 0
	setvar VAR_0x8004, 0
	special InitRoamer
	return

@ ---------------------------------------------------------------------------
@ Event tickets after beating May
SFR_EventScript_BrendanAtHome::
	lock
	faceplayer
	goto_if_set FLAG_SFR_RECEIVED_EON_TICKET, SFR_EventScript_BrendanAtHomeAfter
	msgbox SFR_Text_BrendanEonTicket, MSGBOX_DEFAULT
	giveitem ITEM_EON_TICKET
	goto_if_eq VAR_RESULT, FALSE, SFR_EventScript_TicketNoRoom
	setflag FLAG_SFR_RECEIVED_EON_TICKET
	setflag FLAG_ENABLE_SHIP_SOUTHERN_ISLAND
SFR_EventScript_BrendanAtHomeAfter::
	msgbox SFR_Text_BrendanEonTicketAfter, MSGBOX_DEFAULT
	release
	end

SFR_EventScript_TicketNoRoom::
	release
	end

SFR_EventScript_BrineyOldSeaMap::
	goto_if_set FLAG_SFR_RECEIVED_OLD_SEA_MAP, SFR_EventScript_TicketReturn
	msgbox SFR_Text_BrineyOldSeaMap, MSGBOX_DEFAULT
	giveitem ITEM_OLD_SEA_MAP
	goto_if_eq VAR_RESULT, FALSE, SFR_EventScript_TicketReturn
	setflag FLAG_SFR_RECEIVED_OLD_SEA_MAP
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
	msgbox SFR_Text_TicketUseAtLilycove, MSGBOX_DEFAULT
SFR_EventScript_TicketReturn::
	return

SFR_EventScript_CozmoAuroraTicket::
	goto_if_set FLAG_SFR_RECEIVED_AURORA_TICKET, SFR_EventScript_TicketReturn
	msgbox SFR_Text_CozmoAuroraTicket, MSGBOX_DEFAULT
	giveitem ITEM_AURORA_TICKET
	goto_if_eq VAR_RESULT, FALSE, SFR_EventScript_TicketReturn
	setflag FLAG_SFR_RECEIVED_AURORA_TICKET
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	msgbox SFR_Text_TicketUseAtLilycove, MSGBOX_DEFAULT
	return

SFR_EventScript_WallyMysticTicket::
	goto_if_set FLAG_SFR_RECEIVED_MYSTIC_TICKET, SFR_EventScript_TicketReturn
	msgbox SFR_Text_WallyMysticTicket, MSGBOX_DEFAULT
	giveitem ITEM_MYSTIC_TICKET
	goto_if_eq VAR_RESULT, FALSE, SFR_EventScript_TicketReturn
	setflag FLAG_SFR_RECEIVED_MYSTIC_TICKET
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	msgbox SFR_Text_TicketUseAtLilycove, MSGBOX_DEFAULT
	return

SFR_Text_BrendanEonTicket:
	.string "BRENDAN: {PLAYER}! Congratulations,\n"
	.string "CHAMPION!\p"
	.string "Dad got this from a friend, but I\n"
	.string "think you should have it.\p"
	.string "It's an EON TICKET. It takes you to\n"
	.string "an island in the south where a rare\l"
	.string "POKéMON is said to live.$"

SFR_Text_BrendanEonTicketAfter:
	.string "BRENDAN: Show the ticket to the\n"
	.string "sailor at LILYCOVE's harbor.\p"
	.string "And after that… Let's battle again\n"
	.string "sometime, CHAMPION!$"

SFR_Text_BrineyOldSeaMap:
	.string "MR. BRINEY: Ahoy, CHAMPION!\p"
	.string "While tidying up, I found this old\n"
	.string "map. It shows an island I've never\l"
	.string "sailed to.\p"
	.string "An adventurer like you should have\n"
	.string "it!$"

SFR_Text_CozmoAuroraTicket:
	.string "PROF. COZMO: Ah, the new CHAMPION!\p"
	.string "I've been studying a strange island\n"
	.string "where meteorites fall.\p"
	.string "I can't go there myself, but perhaps\n"
	.string "you could. Please take this ticket!$"

SFR_Text_WallyMysticTicket:
	.string "WALLY: {PLAYER}! You beat MAY!\n"
	.string "That's amazing!\p"
	.string "My uncle got this ticket, but I'm\n"
	.string "not strong enough to use it yet.\p"
	.string "I want you to have it!$"

SFR_Text_TicketUseAtLilycove:
	.string "Show it at LILYCOVE CITY's harbor\n"
	.string "to set sail.$"
