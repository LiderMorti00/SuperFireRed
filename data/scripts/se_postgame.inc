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
	call SE_EventScript_InitKantoPostgame
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
	call SE_EventScript_InitKantoPostgame
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
	.string "BROCK: {PLAYER}! I heard you beat\n"
	.string "RED at the POKéMON LEAGUE!\p"
	.string "My rock-hard POKéMON have trained\n"
	.string "harder than ever.\p"
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
	.string "MISTY: Oh, it's you! The CHAMPION\n"
	.string "who beat RED!\p"
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
	.string "JANINE: Fufufu… The CHAMPION who\n"
	.string "beat RED has come back!\p"
	.string "My father trained me even harder\n"
	.string "after our last battle.\p"
	.string "Will you face my new techniques?$"

SFR_Text_KogaRematchDefeat:
	.string "JANINE: Hmph… I still have a long\n"
	.string "way to go!$"

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

SFR_EventScript_BlueRematch::
	lock
	faceplayer
	msgbox SE_Text_BlueRematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SFR_EventScript_KantoRematchDecline
	cleartrainerflag TRAINER_SE_BLUE_REMATCH
	trainerbattle_no_intro TRAINER_SE_BLUE_REMATCH, SE_Text_BlueRematchDefeat
	msgbox SFR_Text_KantoRematchAfter, MSGBOX_DEFAULT
	release
	end

SE_Text_BlueRematch:
	.string "BLUE: So you actually beat RED…\p"
	.string "Heh. I knew you had it in you.\p"
	.string "But I've been training too.\n"
	.string "Let's see who's stronger now!$"

SE_Text_BlueRematchDefeat:
	.string "BLUE: …Tch. Still can't beat you.\n"
	.string "Next time, for sure!$"

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
	call SFR_EventScript_OakAfterHoenn
	release
	end

SFR_Text_Turtwig:
	.string "TURTWIG$"
SFR_Text_Chimchar:
	.string "CHIMCHAR$"
SFR_Text_Piplup:
	.string "PIPLUP$"

SFR_Text_OakSinnohStarterIntro:
	.string "OAK: {PLAYER}! You beat RED!\n"
	.string "You're the CHAMPION of KANTO, too!\p"
	.string "Two regions… Remarkable!\p"
	.string "To celebrate, I have a gift for you.\p"
	.string "A friend of mine, PROF. ROWAN, sent\n"
	.string "me three POKéMON from SINNOH.\p"
	.string "Like the others, they hold an\n"
	.string "EVERSTONE.$"

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
	.string "Oh, and there's one more thing\n"
	.string "I'd like you to have.$"

SFR_Text_OakShinyCharm:
	.string "OAK: A TRAINER who has become the\n"
	.string "CHAMPION of two regions deserves\l"
	.string "something special.\p"
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

@ ---------------------------------------------------------------------------
@ Kanto, the first time the player sails there: the FireRed story is over
@ (no Team Rocket, Silph Co. and Pokémon Tower back to normal, Saffron open,
@ Snorlax gone), like Kanto in HeartGold / SoulSilver with Cinnabar rebuilt.
SE_EventScript_InitKantoPostgame::
	goto_if_set FLAG_SE_KANTO_INITIALIZED, Common_EventScript_NopReturn
	setflag FLAG_SE_KANTO_INITIALIZED
	setvar VAR_SE_KANTO_ARRIVAL, 1
	@ Pallet Town, Oak's lab, Viridian, Route 22
	setflag FLAG_PALLET_LADY_NOT_BLOCKING_SIGN
	setflag FLAG_VISITED_OAKS_LAB
	setflag FLAG_BEAT_RIVAL_IN_OAKS_LAB
	setflag FLAG_HIDE_RIVAL_IN_LAB
	clearflag FLAG_HIDE_OAK_IN_HIS_LAB
	setflag FLAG_HIDE_OAK_IN_PALLET_TOWN
	setflag FLAG_HIDE_BULBASAUR_BALL
	setflag FLAG_HIDE_SQUIRTLE_BALL
	setflag FLAG_HIDE_CHARMANDER_BALL
	setflag FLAG_GOT_POKEBALLS_FROM_OAK_AFTER_22_RIVAL
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 3
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 9
	setvar VAR_MAP_SCENE_PALLET_TOWN_PLAYERS_HOUSE_2F, 1
	setvar VAR_MAP_SCENE_PALLET_TOWN_RIVALS_HOUSE, 2
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 2
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_MART, 2
	setvar VAR_MAP_SCENE_ROUTE22, 4
	setflag FLAG_HIDE_ROUTE_22_RIVAL
	@ Pewter, Cerulean, Route 24
	setvar VAR_MAP_SCENE_PEWTER_CITY, 2
	setvar VAR_MAP_SCENE_CERULEAN_CITY_RIVAL, 1
	setvar VAR_MAP_SCENE_CERULEAN_CITY_ROCKET, 1
	setvar VAR_MAP_SCENE_ROUTE24, 1
	setflag FLAG_HIDE_CERULEAN_RIVAL
	setflag FLAG_HIDE_CERULEAN_ROCKET
	setflag FLAG_HIDE_NUGGET_BRIDGE_ROCKET
	@ Vermilion: the S.S. Anne has left
	setvar VAR_MAP_SCENE_VERMILION_CITY, 3
	setvar VAR_MAP_SCENE_S_S_ANNE_2F_CORRIDOR, 1
	setflag FLAG_HIDE_SS_ANNE
	setflag FLAG_HIDE_SS_ANNE_RIVAL
	@ Lavender: Pokémon Tower is calm, Mr. Fuji is home
	setvar VAR_MAP_SCENE_POKEMON_TOWER_2F, 1
	setvar VAR_MAP_SCENE_POKEMON_TOWER_6F, 1
	setflag FLAG_HIDE_TOWER_RIVAL
	setflag FLAG_HIDE_TOWER_ROCKET_1
	setflag FLAG_HIDE_TOWER_ROCKET_2
	setflag FLAG_HIDE_TOWER_ROCKET_3
	setflag FLAG_HIDE_TOWER_FUJI
	clearflag FLAG_HIDE_POKEHOUSE_FUJI
	setflag FLAG_RESCUED_MR_FUJI
	@ Celadon: no Rocket Hideout
	setflag FLAG_HIDE_GAME_CORNER_ROCKET
	setflag FLAG_HIDE_CELADON_ROCKETS
	setflag FLAG_HIDE_HIDEOUT_GIOVANNI
	setflag FLAG_HIDE_SILPH_SCOPE
	@ Saffron: Silph Co. freed, gates open
	setvar VAR_MAP_SCENE_ROUTE5_ROUTE6_ROUTE7_ROUTE8_GATES, 1
	setvar VAR_MAP_SCENE_SILPH_CO_7F, 1
	setvar VAR_MAP_SCENE_SILPH_CO_11F, 1
	setflag FLAG_HIDE_SILPH_RIVAL
	setflag FLAG_HIDE_SILPH_ROCKETS
	setflag FLAG_HIDE_SAFFRON_ROCKETS
	clearflag FLAG_HIDE_SAFFRON_CIVILIANS
	setflag FLAG_SILPH_2F_DOOR_1
	setflag FLAG_SILPH_2F_DOOR_2
	setflag FLAG_SILPH_3F_DOOR_1
	setflag FLAG_SILPH_3F_DOOR_2
	setflag FLAG_SILPH_4F_DOOR_1
	setflag FLAG_SILPH_4F_DOOR_2
	setflag FLAG_SILPH_5F_DOOR_1
	setflag FLAG_SILPH_5F_DOOR_2
	setflag FLAG_SILPH_5F_DOOR_3
	setflag FLAG_SILPH_6F_DOOR
	setflag FLAG_SILPH_7F_DOOR_1
	setflag FLAG_SILPH_7F_DOOR_2
	setflag FLAG_SILPH_7F_DOOR_3
	setflag FLAG_SILPH_8F_DOOR
	setflag FLAG_SILPH_9F_DOOR_1
	setflag FLAG_SILPH_9F_DOOR_2
	setflag FLAG_SILPH_9F_DOOR_3
	setflag FLAG_SILPH_9F_DOOR_4
	setflag FLAG_SILPH_10F_DOOR
	setflag FLAG_SILPH_11F_DOOR
	@ Snorlax no longer blocks Routes 12 and 16
	setflag FLAG_HIDE_ROUTE_12_SNORLAX
	setflag FLAG_WOKE_UP_ROUTE_12_SNORLAX
	setflag FLAG_HIDE_ROUTE_16_SNORLAX
	@ Cinnabar Gym is open (Blaine's Secret Key not needed)
	setflag FLAG_HIDE_POKEMON_MANSION_B1F_SECRET_KEY
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND, 4
	@ Every other Team Rocket member in Kanto and the Sevii Islands
	setflag FLAG_HIDE_MISC_KANTO_ROCKETS
	setflag FLAG_HIDE_FIVE_ISLAND_ROCKETS
	setflag FLAG_HIDE_MT_EMBER_EXTERIOR_ROCKETS
	setflag FLAG_HIDE_ICEFALL_CAVE_ROCKETS
	@ Sevii Islands: exploration only, the Bill/Celio story is already over
	setflag FLAG_SYS_SEVII_MAP_123
	setflag FLAG_SYS_SEVII_MAP_4567
	setflag FLAG_SEVII_DETOUR_FINISHED
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_2, 2
	setvar VAR_MAP_SCENE_ONE_ISLAND_HARBOR, 3
	setvar VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 7
	setflag FLAG_HIDE_CINNABAR_BILL
	setflag FLAG_HIDE_CINNABAR_POKECENTER_BILL
	setflag FLAG_HIDE_ONE_ISLAND_BILL
	setflag FLAG_HIDE_ONE_ISLAND_POKECENTER_BILL
	@ Two and Three Island: Lostelle is home, the bikers are gone
	setvar VAR_MAP_SCENE_TWO_ISLAND_JOYFUL_GAME_CORNER, 4
	setflag FLAG_RESCUED_LOSTELLE
	setflag FLAG_GOT_MOON_STONE_FROM_JOYFUL_GAME_CORNER
	setflag FLAG_HIDE_LOSTELLE_IN_BERRY_FOREST
	setflag FLAG_HIDE_TWO_ISLAND_GAME_CORNER_LOSTELLE
	setflag FLAG_HIDE_TWO_ISLAND_GAME_CORNER_BIKER
	clearflag FLAG_HIDE_LOSTELLE_IN_HER_HOME
	setvar VAR_MAP_SCENE_THREE_ISLAND, 4
	setflag FLAG_HIDE_THREE_ISLAND_BIKERS
	setflag FLAG_HIDE_THREE_ISLAND_LONE_BIKER
	setflag FLAG_HIDE_THREE_ISLAND_ANTIBIKERS
	@ Four Island: Lorelei is at home, no rival
	setvar VAR_MAP_SCENE_FOUR_ISLAND, 1
	setvar VAR_MAP_SCENE_ICEFALL_CAVE_BACK, 1
	setflag FLAG_HIDE_FOUR_ISLAND_RIVAL
	setflag FLAG_HIDE_ICEFALL_CAVE_LORELEI
	clearflag FLAG_HIDE_LORELEI_IN_HER_HOUSE
	@ Five Island: the warehouse is empty and open
	setvar VAR_MAP_SCENE_ROCKET_WAREHOUSE, 1
	setflag FLAG_UNLOCKED_ROCKET_WAREHOUSE
	setflag FLAG_DEFEATED_ROCKETS_IN_WAREHOUSE
	@ Mt. Ember and Six Island: no RUBY, no SAPPHIRE, no thief
	setvar VAR_MAP_SCENE_MT_EMBER_EXTERIOR, 2
	setflag FLAG_HIDE_RUBY
	setflag FLAG_HIDE_SAPPHIRE
	setflag FLAG_HIDE_DOTTED_HOLE_SCIENTIST
	setvar VAR_MAP_SCENE_SIX_ISLAND_POKEMON_CENTER_1F, 1
	setflag FLAG_HIDE_SIX_ISLAND_POKECENTER_RIVAL
	return

@ ---------------------------------------------------------------------------
@ Vermilion City: Prof. Oak meets the player at the dock with a Kanto starter
SE_EventScript_VermilionOakArrival::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	clearflag FLAG_SE_HIDE_VERMILION_OAK
	addobject LOCALID_VERMILION_SE_OAK
	applymovement LOCALID_VERMILION_SE_OAK, SE_Movement_VermilionOakApproach
	waitmovement 0
	msgbox SE_Text_VermilionOakWelcome, MSGBOX_DEFAULT
SE_EventScript_VermilionOakChoose::
	message SE_Text_OakWhichKantoStarter
	waitmessage
	dynmultipush SE_Text_Bulbasaur, 0
	dynmultipush SE_Text_Charmander, 1
	dynmultipush SE_Text_Squirtle, 2
	dynmultichoice 20, 4, TRUE, 3, 0, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, SE_EventScript_OakBulbasaur
	case 1, SE_EventScript_OakCharmander
	setvar VAR_0x8004, SPECIES_SQUIRTLE
	goto SE_EventScript_OakConfirmKantoStarter
	end

SE_EventScript_OakBulbasaur::
	setvar VAR_0x8004, SPECIES_BULBASAUR
	goto SE_EventScript_OakConfirmKantoStarter
	end

SE_EventScript_OakCharmander::
	setvar VAR_0x8004, SPECIES_CHARMANDER
	goto SE_EventScript_OakConfirmKantoStarter
	end

SE_EventScript_OakConfirmKantoStarter::
	bufferspeciesname STR_VAR_1, VAR_0x8004
	showmonpic VAR_0x8004, 10, 3
	msgbox SFR_Text_OakSoYouWant, MSGBOX_YESNO
	hidemonpic
	goto_if_eq VAR_RESULT, NO, SE_EventScript_VermilionOakChoose
	givemon VAR_0x8004, 45, ITEM_EVERSTONE
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, SE_EventScript_OakKantoStarterParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, SE_EventScript_OakKantoStarterPC
	msgbox gText_NoMoreRoomForPokemon, MSGBOX_DEFAULT
	releaseall
	end

SE_EventScript_OakKantoStarterParty::
	call SE_EventScript_OakReceivedKantoStarter
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SE_EventScript_OakKantoStarterEnd
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto SE_EventScript_OakKantoStarterEnd
	end

SE_EventScript_OakKantoStarterPC::
	call SE_EventScript_OakReceivedKantoStarter
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SE_EventScript_OakKantoStarterSent
	call Common_EventScript_NameReceivedBoxMon
SE_EventScript_OakKantoStarterSent::
	call Common_EventScript_TransferredToPC
	goto SE_EventScript_OakKantoStarterEnd
	end

SE_EventScript_OakReceivedKantoStarter::
	setvar VAR_SE_KANTO_ARRIVAL, 2
	playfanfare MUS_OBTAIN_ITEM
	message SE_Text_ReceivedKantoStarter
	waitmessage
	waitfanfare
	return

SE_EventScript_OakKantoStarterEnd::
	msgbox SE_Text_VermilionOakRainbowPass, MSGBOX_DEFAULT
	giveitem ITEM_RAINBOW_PASS
	msgbox SE_Text_VermilionOakGoodbye, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VERMILION_SE_OAK, SE_Movement_VermilionOakLeave
	waitmovement 0
	removeobject LOCALID_VERMILION_SE_OAK
	setflag FLAG_SE_HIDE_VERMILION_OAK
	releaseall
	end

SE_Movement_VermilionOakApproach:
	walk_up
	step_end

SE_Movement_VermilionOakLeave:
	walk_down
	step_end

SE_Text_Bulbasaur:
	.string "BULBASAUR$"
SE_Text_Charmander:
	.string "CHARMANDER$"
SE_Text_Squirtle:
	.string "SQUIRTLE$"

SE_Text_VermilionOakWelcome:
	.string "OAK: Ah, you must be {PLAYER}!\n"
	.string "Welcome to KANTO!\p"
	.string "I'm PROF. OAK. BIRCH told me all\n"
	.string "about the new CHAMPION of HOENN.\p"
	.string "KANTO has eight GYMS of its own,\n"
	.string "and the POKéMON LEAGUE is waiting\l"
	.string "at INDIGO PLATEAU.\p"
	.string "To start you off, I'd like you\n"
	.string "to have one of these POKéMON.\p"
	.string "They're well trained, and each\n"
	.string "one holds an EVERSTONE.$"

SE_Text_OakWhichKantoStarter:
	.string "Which one will you choose?$"

SE_Text_ReceivedKantoStarter:
	.string "{PLAYER} received the {STR_VAR_1}\n"
	.string "from PROF. OAK!$"

SE_Text_VermilionOakRainbowPass:
	.string "OAK: Oh, and take this as well.\p"
	.string "It's a RAINBOW PASS. Show it to the\n"
	.string "SEAGALLOP crew here in VERMILION.\p"
	.string "The ferry will take you to all of\n"
	.string "the SEVII ISLANDS.$"

SE_Text_VermilionOakGoodbye:
	.string "OAK: My lab is in PALLET TOWN.\n"
	.string "Come and visit me anytime!\p"
	.string "And if you beat the CHAMPION here,\n"
	.string "I'll have something special for you.$"
