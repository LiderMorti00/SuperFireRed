@ Pokémon Super Emerald: postgame scripts (Kanto and Hoenn) carried over from Super Fire Red.
@ Kanto ones are reworked in the Kanto blocks; Hoenn ones are unlocked by FLAG_SYS_GAME_CLEAR.

@ ---------------------------------------------------------------------------
@ Vermilion City: sailor of the S.S. Tidal, Kanto -> Slateport
SFR_EventScript_VermilionHoennSailor::
	lock
	faceplayer
	msgbox SFR_Text_VermilionSailorBoardToSlateport, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SFR_EventScript_VermilionHoennSailorDeclined
	msgbox SFR_Text_VermilionSailorAllAboard, MSGBOX_DEFAULT
	closemessage
	playse SE_SHIP
	fadescreenspeed FADE_TO_BLACK, 12
	delay 60
	warp MAP_SLATEPORT_CITY_HARBOR, 8, 11
	waitstate
	release
	end

SFR_EventScript_VermilionHoennSailorDeclined::
	msgbox SFR_Text_VermilionSailorComeBackAnytime, MSGBOX_DEFAULT
	release
	end

SFR_Text_VermilionSailorBoardToSlateport:
	.string "The S.S. TIDAL is bound for\n"
	.string "SLATEPORT CITY in HOENN.\p"
	.string "Would you like to board?$"

SFR_Text_VermilionSailorAllAboard:
	.string "All aboard!$"

SFR_Text_VermilionSailorComeBackAnytime:
	.string "Come back whenever you're ready\n"
	.string "to set sail.$"

@ ---------------------------------------------------------------------------
@ Slateport / Lilycove harbors: S.S. Tidal to Vermilion City with the Kanto Ticket
SE_EventScript_SlateportOfferKanto::
	checkitem ITEM_KANTO_TICKET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_NopReturn
	msgbox SE_Text_HarborKantoTicket, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Common_EventScript_NopReturn
	call SlateportCity_Harbor_EventScript_BoardFerry
	warp MAP_VERMILION_CITY, 23, 32
	waitstate
	release
	end

SE_EventScript_LilycoveOfferKanto::
	checkitem ITEM_KANTO_TICKET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_NopReturn
	msgbox SE_Text_HarborKantoTicket, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Common_EventScript_NopReturn
	call LilycoveCity_Harbor_EventScript_BoardFerry
	warp MAP_VERMILION_CITY, 23, 32
	waitstate
	release
	end

SE_Text_HarborKantoTicket:
	.string "Oh, that's a KANTO TICKET!\p"
	.string "Would you like to sail to\n"
	.string "VERMILION CITY in KANTO?$"

@ ---------------------------------------------------------------------------
@ Kanto Gym Leader rematches
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
@ ---------------------------------------------------------------------------
@ Oak: Sinnoh starter and Shiny Charm
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
@ ---------------------------------------------------------------------------
@ Regidrago, Regigigas and Regieleki
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
	setwildbattle SPECIES_REGIELEKI, 75
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
	setwildbattle SPECIES_REGIDRAGO, 75
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



@ ---------------------------------------------------------------------------
@ Event tickets after becoming Champion
SE_EventScript_RivalEonTicket::
	goto_if_set FLAG_SFR_RECEIVED_EON_TICKET, Common_EventScript_NopReturn
	msgbox SE_Text_RivalEonTicket, MSGBOX_DEFAULT
	giveitem ITEM_EON_TICKET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_NopReturn
	setflag FLAG_SFR_RECEIVED_EON_TICKET
	setflag FLAG_ENABLE_SHIP_SOUTHERN_ISLAND
	msgbox SE_Text_TicketUseAtLilycove, MSGBOX_DEFAULT
	return

SE_EventScript_BrineyOldSeaMap::
	goto_if_set FLAG_SFR_RECEIVED_OLD_SEA_MAP, Common_EventScript_NopReturn
	msgbox SE_Text_BrineyOldSeaMap, MSGBOX_DEFAULT
	giveitem ITEM_OLD_SEA_MAP
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_NopReturn
	setflag FLAG_SFR_RECEIVED_OLD_SEA_MAP
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
	msgbox SE_Text_TicketUseAtLilycove, MSGBOX_DEFAULT
	return

SE_EventScript_CozmoAuroraTicket::
	goto_if_set FLAG_SFR_RECEIVED_AURORA_TICKET, Common_EventScript_NopReturn
	msgbox SE_Text_CozmoAuroraTicket, MSGBOX_DEFAULT
	giveitem ITEM_AURORA_TICKET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_NopReturn
	setflag FLAG_SFR_RECEIVED_AURORA_TICKET
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	msgbox SE_Text_TicketUseAtLilycove, MSGBOX_DEFAULT
	return

SE_EventScript_WallyMysticTicket::
	goto_if_set FLAG_SFR_RECEIVED_MYSTIC_TICKET, Common_EventScript_NopReturn
	msgbox SE_Text_WallyMysticTicket, MSGBOX_DEFAULT
	giveitem ITEM_MYSTIC_TICKET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_NopReturn
	setflag FLAG_SFR_RECEIVED_MYSTIC_TICKET
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	msgbox SE_Text_TicketUseAtLilycove, MSGBOX_DEFAULT
	return

SE_Text_RivalEonTicket:
	.string "{RIVAL}: {PLAYER}{KUN}! Congratulations,\n"
	.string "CHAMPION!\p"
	.string "Dad got this from a friend, but I\n"
	.string "think you should have it.\p"
	.string "It's an EON TICKET. It takes you to\n"
	.string "an island in the south where a rare\l"
	.string "POKéMON is said to live.$"

SE_Text_BrineyOldSeaMap:
	.string "MR. BRINEY: Ahoy, CHAMPION!\p"
	.string "While tidying up, I found this old\n"
	.string "map. It shows an island I've never\l"
	.string "sailed to.\p"
	.string "An adventurer like you should have\n"
	.string "it!$"

SE_Text_CozmoAuroraTicket:
	.string "PROF. COZMO: Ah, the new CHAMPION!\p"
	.string "I've been studying a strange island\n"
	.string "where meteorites fall.\p"
	.string "I can't go there myself, but perhaps\n"
	.string "you could. Please take this ticket!$"

SE_Text_WallyMysticTicket:
	.string "WALLY: {PLAYER}! You're the CHAMPION\n"
	.string "now. That's amazing!\p"
	.string "My uncle got this ticket, but I'm\n"
	.string "not strong enough to use it yet.\p"
	.string "I want you to have it!$"

SE_Text_TicketUseAtLilycove:
	.string "Show it at LILYCOVE CITY's harbor\n"
	.string "to set sail.$"
