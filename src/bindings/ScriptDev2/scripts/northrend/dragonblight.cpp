/* Copyright (C) 2006 - 2011 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* ScriptData
SDName: Dragonblight
SD%Complete: 100
SDComment: Quest support: 12166, 12499/12500(end sequenze). Taxi paths Wyrmrest temple.
SDCategory: Dragonblight
EndScriptData */

/* ContentData
npc_afrasastrasz
npc_alexstrasza_wr_gate
npc_liquid_fire_of_elune
npc_tariolstrasz
npc_torastrasza
EndContentData */

#include "precompiled.h"
#include "escort_ai.h"

/*######
## npc_afrasastrasz
######*/

enum
{
    TAXI_PATH_ID_MIDDLE_DOWN            = 882,
    TAXI_PATH_ID_MIDDLE_TOP             = 881
};

#define GOSSIP_ITEM_TAXI_MIDDLE_DOWN    "I would like to take a flight to the ground, Lord Of Afrasastrasz."
#define GOSSIP_ITEM_TAXI_MIDDLE_TOP     "My Lord, I must go to the upper floor of the temple."

bool GossipHello_npc_afrasastrasz(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_TAXI_MIDDLE_DOWN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_TAXI_MIDDLE_TOP, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);

    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_afrasastrasz(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        pPlayer->ActivateTaxiPathTo(TAXI_PATH_ID_MIDDLE_DOWN);
    }
    if (uiAction == GOSSIP_ACTION_INFO_DEF+2)
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        pPlayer->ActivateTaxiPathTo(TAXI_PATH_ID_MIDDLE_TOP);
    }
    return true;
}

/*######
## npc_alexstrasza_wr_gate
######*/

enum
{
    QUEST_RETURN_TO_AG_A    = 12499,
    QUEST_RETURN_TO_AG_H    = 12500,
    MOVIE_ID_GATES          = 14
};

#define GOSSIP_ITEM_WHAT_HAPPENED   "Alexstrasza, can you show me what happened here?"

bool GossipHello_npc_alexstrasza_wr_gate(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if (pPlayer->GetQuestRewardStatus(QUEST_RETURN_TO_AG_A) || pPlayer->GetQuestRewardStatus(QUEST_RETURN_TO_AG_H))
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_WHAT_HAPPENED, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_alexstrasza_wr_gate(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        pPlayer->SendMovieStart(MOVIE_ID_GATES);
    }

    return true;
}

/*######
## npc_tariolstrasz
######*/

enum
{
    QUEST_INFORM_QUEEN_A                = 12123,            //need to check if quests are required before gossip available
    QUEST_INFORM_QUEEN_H                = 12124,
    TAXI_PATH_ID_BOTTOM_TOP             = 878,
    TAXI_PATH_ID_BOTTOM_MIDDLE          = 883
};

#define GOSSIP_ITEM_TAXI_BOTTOM_TOP     "My Lord, I must go to the upper floor of the temple."
#define GOSSIP_ITEM_TAXI_BOTTOM_MIDDLE  "Can you spare a drake to travel to Lord Of Afrasastrasz, in the middle of the temple?"

bool GossipHello_npc_tariolstrasz(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_TAXI_BOTTOM_TOP, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_TAXI_BOTTOM_MIDDLE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);

    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_tariolstrasz(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        pPlayer->ActivateTaxiPathTo(TAXI_PATH_ID_BOTTOM_TOP);
    }
    if (uiAction == GOSSIP_ACTION_INFO_DEF+2)
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        pPlayer->ActivateTaxiPathTo(TAXI_PATH_ID_BOTTOM_MIDDLE);
    }
    return true;
}

/*######
## npc_torastrasza
######*/

enum
{
    TAXI_PATH_ID_TOP_MIDDLE             = 880,
    TAXI_PATH_ID_TOP_BOTTOM             = 879
};

#define GOSSIP_ITEM_TAXI_TOP_MIDDLE     "I would like to see Lord Of Afrasastrasz, in the middle of the temple."
#define GOSSIP_ITEM_TAXI_TOP_BOTTOM     "Yes, Please. I would like to return to the ground floor of the temple."

bool GossipHello_npc_torastrasza(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_TAXI_TOP_MIDDLE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_TAXI_TOP_BOTTOM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);

    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_torastrasza(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        pPlayer->ActivateTaxiPathTo(TAXI_PATH_ID_TOP_MIDDLE);
    }
    if (uiAction == GOSSIP_ACTION_INFO_DEF+2)
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        pPlayer->ActivateTaxiPathTo(TAXI_PATH_ID_TOP_BOTTOM);
    }
    return true;
}

/*######
## go_abbey_bell_rope
######*/

enum
{
    NPC_ONSLAUGHT_RAVEN_PRIEST          = 27202,
    SOUND_NORTHSHIRE_BELL               = 7256,

    SAY_AFTER_BELL_RANG                 = -1999850,
    SAY_HIGH_ABBOT_BEGINING             = -1999849,
    SAY_HIGH_ABBOT_CLIFF_1              = -1999848,
    SAY_HIGH_ABBOT_CLIFF_2              = -1999847,
    SAY_HIGH_ABBOT_CLIFF_3              = -1999846,
    SAY_HIGH_ABBOT_CLIFF_4              = -1999845,
    SAY_HIGH_ABBOT_CLIFF_5              = -1999844,

    SPELL_KILL_ABBOT_CREDIT             = 48771,
    SPELL_ABBOT_RIDE_VEHICLE            = 48773,
    SPELL_KISSED_RING                   = 48756,
    SPELL_SUMMON_ABBOT_FORCED_CAST      = 48759,
    SPELL_BELL_RANG                     = 48753,
    
    GOSSIP_TEXTID_1                     = 12848,
    GOSSIP_TEXTID_2                     = 12849,

    QUEST_A_FALL_FROM_GREACE            = 12274,

    NPC_ABBOT                           = 27439
};

bool GOUse_go_abbey_bell_rope(Player* pPlayer, GameObject* pGo)
{
    if (!pGo || !pPlayer)
        return false;

    pPlayer->CastSpell(pPlayer,SPELL_BELL_RANG,true);
    pGo->PlayDirectSound(SOUND_NORTHSHIRE_BELL);
    if (Creature* pPriest = GetClosestCreatureWithEntry(pGo,NPC_ONSLAUGHT_RAVEN_PRIEST,INTERACTION_DISTANCE*2))
    {
        pPriest->SetFacingToObject(pPlayer);
        DoScriptText(SAY_AFTER_BELL_RANG,pPriest);
    }
    return false;
}

/*######
## npc_abbot_to_escort
######*/

struct MANGOS_DLL_DECL npc_abbot_to_escortAI : public npc_escortAI
{
    npc_abbot_to_escortAI(Creature* pCreature) : npc_escortAI(pCreature) { Reset(); }

    uint32 PointStarted;
    uint8  subevent;
    uint32 m_uiEvent_Timer;
    bool bReady;

    void Reset()
    {
        bReady = true;
        PointStarted = 0;
        subevent = 0;
        m_uiEvent_Timer = 0;
    }

    void MoveInLineOfSight(Unit *pWho)
    {
        if (!bReady || !pWho)
            return;

        Player* pPlayer = GetPlayerForEscort();
        if (!pPlayer)
            return;

        if ((pWho->GetGUID() == pPlayer->GetGUID()) && (m_creature->GetDistance(pPlayer)<= INTERACTION_DISTANCE))
        {
            // Don't know why crashing server : / so temp removed
            //m_creature->SetVisibility(VISIBILITY_ON);
            bReady = false;
        }
    }

    void WaypointReached(uint32 uiPointId) {}
    void WaypointStart(uint32 uiPointId)
    {
        switch(uiPointId)
        {
            case 10:
                m_uiEvent_Timer = 0;
            case 0:
                subevent = 0;
                break;
            default: break;
        }
        PointStarted = uiPointId;
    }
    void UpdateEscortAI(const uint32 uiDiff)
    {
        Player* pPlayer = GetPlayerForEscort();
        if (!pPlayer || bReady)
            return;

        if (m_uiEvent_Timer <= uiDiff)
        {
            switch (PointStarted)
            {
                case 0:
                    switch (subevent)
                    {
                        // Abbot speaks few secounds after emerging
                        case 0: SetEscortPaused(true); break;
                        case 1:
                            m_creature->SetFacingToObject(pPlayer);
                            DoScriptText(SAY_HIGH_ABBOT_BEGINING, m_creature);
                            break;
                        case 2: SetEscortPaused(false); break;
                        
                        default: break;
                    }
                    break;
                case 10:
                    switch (subevent)
                    {
                        case 0: SetEscortPaused(true); break;
                        case 1: m_creature->SetFacingToObject(pPlayer);
                            DoScriptText(SAY_HIGH_ABBOT_CLIFF_1, m_creature, pPlayer); break;
                        case 2: DoScriptText(SAY_HIGH_ABBOT_CLIFF_2, m_creature, pPlayer); break;
                        case 3: DoScriptText(SAY_HIGH_ABBOT_CLIFF_3 ,m_creature, pPlayer); break;
                        case 4: DoScriptText(SAY_HIGH_ABBOT_CLIFF_4, m_creature, pPlayer); break;
                        case 5: 
                            DoScriptText(SAY_HIGH_ABBOT_CLIFF_5, m_creature, pPlayer);
                            // pPlayer->CastSpell(pPlayer, SPELL_KILL_ABBOT_CREDIT, true);
                            // Hack - SPELL_KILL_ABBOT_CREDIT is not working
                            pPlayer->KilledMonsterCredit(27444, m_creature->GetGUID());
                            // DoCast(m_creature,SPELL_ABBOT_RIDE_VEHICLE,true);
                            // Hack - SPELL_ABBOT_RIDE_VEHICLE is not working
                            m_creature->KnockBackFrom(pPlayer, 12.0f, 12.0f);
                            break;
                        case 6: m_creature->ForcedDespawn();
                        default: break;
                    }
                    break;
                default: break;
            }
            ++subevent;
            m_uiEvent_Timer = 5000;
        }else m_uiEvent_Timer -= uiDiff;
    }
};

/*######
## npc_abbot_landgren
######*/

#define GOSSIP_ITEM_ABBOT_1     "Your eminence, may I have a word in private?"
#define GOSSIP_ITEM_ABBOT_2     "I am ready, your grace. <kiss the ring>"
float Abbot[] = {2827.27f, -447.32f, 119.62f, 1.68f};

bool GossipHello_npc_abbot_landgren(Player* pPlayer, Creature* pCreature)
{
    if (pPlayer->GetQuestStatus(QUEST_A_FALL_FROM_GREACE) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_ABBOT_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_abbot_landgren(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
    {
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_ABBOT_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
        pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_1, pCreature->GetGUID());
        // SPELL_KISSED_RING does not work
        // pPlayer->CastSpell(pCreature,SPELL_KISSED_RING,true);
    }
    if (uiAction == GOSSIP_ACTION_INFO_DEF+2)
    {
        pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_2, pCreature->GetGUID());

        // DoCast(pCreature,SPELL_SUMMON_ABBOT_FORCED_CAST,true);
        // Hack - SPELL_SUMMON_ABBOT_FORCED_CAST is not supported
        if (Creature* pAbbot = pPlayer->SummonCreature(NPC_ABBOT, Abbot[0], Abbot[1], Abbot[2], Abbot[3], TEMPSUMMON_CORPSE_DESPAWN, 0))
        {
            if (npc_abbot_to_escortAI* pEscortAI = dynamic_cast<npc_abbot_to_escortAI*>(pAbbot->AI()))
            {
                pEscortAI->Start(false, pPlayer->GetGUID());
                pEscortAI->SetEscortPaused(true);
                // Don't know why crashing server : / so temp removed
                //pAbbot->SetVisibility(VISIBILITY_OFF);
            }
        }
    }
    return true;
}
CreatureAI* GetAI_npc_abbot_to_escort(Creature* pCreature)
{
    return new npc_abbot_to_escortAI(pCreature);
}

/*######
/*######
## mob_maggot
######*/
#define NPC_BLOODFEAST       27008

struct MANGOS_DLL_DECL mob_maggotAI : public ScriptedAI
{
    mob_maggotAI(Creature* pCreature) : ScriptedAI(pCreature) { Reset(); }

    void Reset() {}

    void DamageDeal(Unit* pDoneTo, uint32& uiDamage)
    {
        if (!pDoneTo || !uiDamage)
            return;

        if (Creature* pBloodfeast = GetClosestCreatureWithEntry(m_creature, NPC_BLOODFEAST, INTERACTION_DISTANCE*2))
            if (pBloodfeast->GetHealth() < pBloodfeast->GetMaxHealth())
                pBloodfeast->SetHealth(pBloodfeast->GetHealth()+ uiDamage);
    }
};
CreatureAI* GetAI_mob_maggot(Creature* pCreature)
{
    return new mob_maggotAI(pCreature);
}

/*######
## npc_hourglass_of_eternity
######*/
/*Support for 'Future you' is currently missing*/ 
enum
{
    NPC_INFINITE_CHRONO_MAGUS    = 27898,
    NPC_INFINITE_ASSAILANT       = 27896,
    NPC_INFINITE_DESTROYER       = 27897,
    NPC_INFINITE_TIMERENDER      = 27900,
    QUEST_MYSTERY_OF_INFINITE    = 12470

};

struct MANGOS_DLL_DECL npc_hourglassAI : public ScriptedAI
{
    npc_hourglassAI(Creature* pCreature) : ScriptedAI(pCreature) { Reset(); }
    
    uint64 uiWaveTimer;
    uint32 uiWaveCounter;

     void Reset()
     {
         uiWaveTimer = 5000;
         uiWaveCounter = 0;
     }

     void JustSummoned(Creature* pSummoned)
     {
         pSummoned->AI()->AttackStart(m_creature);
     }  

     void JustDied(Unit* pKiller)
     {
        if(Player *pPlayer = m_creature->GetMap()->GetPlayer(m_creature->GetOwnerGuid()))
        {
            pPlayer->FailQuest(QUEST_MYSTERY_OF_INFINITE);
        }
     }

     void SummonWave()
     {
         switch(uiWaveCounter)
         {
            case 0: m_creature->SummonCreature(NPC_INFINITE_CHRONO_MAGUS, m_creature->GetPositionX()+5,m_creature->GetPositionY(),m_creature->GetPositionZ(), 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                    m_creature->SummonCreature(NPC_INFINITE_ASSAILANT, m_creature->GetPositionX()-5,m_creature->GetPositionY(),m_creature->GetPositionZ(), 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                    break;
            case 1: m_creature->SummonCreature(NPC_INFINITE_CHRONO_MAGUS, m_creature->GetPositionX()+5,m_creature->GetPositionY(),m_creature->GetPositionZ(), 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                    m_creature->SummonCreature(NPC_INFINITE_CHRONO_MAGUS, m_creature->GetPositionX()-5,m_creature->GetPositionY(),m_creature->GetPositionZ(), 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                    break;
            case 2: m_creature->SummonCreature(NPC_INFINITE_CHRONO_MAGUS, m_creature->GetPositionX()+5,m_creature->GetPositionY(),m_creature->GetPositionZ(), 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                    m_creature->SummonCreature(NPC_INFINITE_ASSAILANT, m_creature->GetPositionX()-5,m_creature->GetPositionY(),m_creature->GetPositionZ(), 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                    m_creature->SummonCreature(NPC_INFINITE_DESTROYER, m_creature->GetPositionX()+5,m_creature->GetPositionY()+5 ,m_creature->GetPositionZ(), 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                    break;
            case 3: m_creature->SummonCreature(NPC_INFINITE_CHRONO_MAGUS, m_creature->GetPositionX()+5,m_creature->GetPositionY(),m_creature->GetPositionZ(), 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                    m_creature->SummonCreature(NPC_INFINITE_ASSAILANT, m_creature->GetPositionX()-5,m_creature->GetPositionY(),m_creature->GetPositionZ(), 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                    m_creature->SummonCreature(NPC_INFINITE_DESTROYER, m_creature->GetPositionX()+5,m_creature->GetPositionY()+5 ,m_creature->GetPositionZ(), 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                    break;
            case 4: m_creature->SummonCreature(NPC_INFINITE_TIMERENDER, m_creature->GetPositionX()+5,m_creature->GetPositionY(),m_creature->GetPositionZ(), 0, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300000);
                    break;

         }
     }
     void UpdateAI(const uint32 uiDiff)
     {
            if (uiWaveTimer <= uiDiff)
            {
                if(uiWaveCounter<=4)
                {
                    SummonWave();
                    uiWaveTimer = 15000;
                    uiWaveCounter++;
                }
                else m_creature->ForcedDespawn();

            } else uiWaveTimer -= uiDiff;
     }
};

CreatureAI* GetAI_npc_hourglass(Creature* pCreature)
{
    return new npc_hourglassAI(pCreature);
}

/*######
## npc_vehicle
######*/
enum 
{
    NPC_WYRMREST_DEFENDER      = 27629,
    NPC_WINTERGARDE_GRYPHOON   = 27258
};

struct MANGOS_DLL_DECL npc_vehicleAI : public ScriptedAI
{
    npc_vehicleAI(Creature* pCreature) : ScriptedAI(pCreature) { Reset(); }

    uint32 uiCheckTimer;
    void Reset() 
    {
        uiCheckTimer = 15000;
    }

    void UpdateAI(const uint32 uiDiff)
     {
            if (uiCheckTimer <= uiDiff)
            {
                switch(m_creature->GetEntry())
                {
                    case NPC_WYRMREST_DEFENDER: if(m_creature->GetAreaId() != 4254 && m_creature->GetAreaId() != 4183 && m_creature->GetAreaId() != 4161)
                                                 {
                                                     m_creature->ForcedDespawn();
                                                 }
                                                 break;
                    case NPC_WINTERGARDE_GRYPHOON: if(m_creature->GetAreaId() != 4177 && m_creature->GetAreaId() != 4188)
                                                    {
                                                        m_creature->ForcedDespawn();
                                                    }
                                                    break;
                }
                uiCheckTimer = 10000;

            } else uiCheckTimer -= uiDiff;
     }

    
};
CreatureAI* GetAI_npc_vehicle(Creature* pCreature)
{
    return new npc_vehicleAI(pCreature);
}

/*######
## npc_destructive_ward
######*/
enum
{
    NPC_SMOLDERING_SKELETON    = 27360,
    NPC_SMOLDERING_CONSTRUCT   = 27362,
    KILL_CREDIT_BUNNY          = 28820,
    QUEST_NO_PLACE_TO_RUN      = 12261,
    WARD_EMOTE_1               = -1799900,
    WARD_EMOTE_2               = -1799901

};

struct MANGOS_DLL_DECL npc_destructive_wardAI : public ScriptedAI
{
    npc_destructive_wardAI(Creature* pCreature) : ScriptedAI(pCreature) { Reset(); }
    
    uint64 uiWaveTimer;
    uint32 uiWaveCounter;

     void Reset()
     {
         uiWaveTimer = 2000;
         uiWaveCounter = 0;
     }

     void JustSummoned(Creature* pSummoned)
     {
         pSummoned->AI()->AttackStart(m_creature);
     }  

     void JustDied(Unit* pKiller)
     {
        if(Player *pPlayer = m_creature->GetMap()->GetPlayer(m_creature->GetOwnerGuid()))
        {
            pPlayer->FailQuest(QUEST_NO_PLACE_TO_RUN);
        }
     }

     void SummonWave()
     {
         switch(uiWaveCounter)
         {
            case 0: m_creature->SummonCreature(NPC_SMOLDERING_SKELETON, m_creature->GetPositionX()+5,m_creature->GetPositionY(),m_creature->GetPositionZ(), 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                    m_creature->SummonCreature(NPC_SMOLDERING_SKELETON, m_creature->GetPositionX()-5,m_creature->GetPositionY(),m_creature->GetPositionZ(), 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                    break;
            case 1: m_creature->SummonCreature(NPC_SMOLDERING_CONSTRUCT, m_creature->GetPositionX()+5,m_creature->GetPositionY(),m_creature->GetPositionZ(), 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                    m_creature->SummonCreature(NPC_SMOLDERING_CONSTRUCT, m_creature->GetPositionX()-5,m_creature->GetPositionY(),m_creature->GetPositionZ(), 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                    m_creature->SummonCreature(NPC_SMOLDERING_SKELETON, m_creature->GetPositionX()-5,m_creature->GetPositionY(),m_creature->GetPositionZ(), 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                    DoScriptText(WARD_EMOTE_1, m_creature);
                    break;
            case 2: m_creature->SummonCreature(NPC_SMOLDERING_CONSTRUCT, m_creature->GetPositionX()+5,m_creature->GetPositionY(),m_creature->GetPositionZ(), 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                    m_creature->SummonCreature(NPC_SMOLDERING_CONSTRUCT, m_creature->GetPositionX()-5,m_creature->GetPositionY(),m_creature->GetPositionZ(), 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                    m_creature->SummonCreature(NPC_SMOLDERING_SKELETON, m_creature->GetPositionX()-5,m_creature->GetPositionY(),m_creature->GetPositionZ(), 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                    DoScriptText(WARD_EMOTE_1, m_creature);
                    break;
            case 3: m_creature->SummonCreature(NPC_SMOLDERING_CONSTRUCT, m_creature->GetPositionX()+5,m_creature->GetPositionY(),m_creature->GetPositionZ(), 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                    m_creature->SummonCreature(NPC_SMOLDERING_CONSTRUCT, m_creature->GetPositionX()-5,m_creature->GetPositionY(),m_creature->GetPositionZ(), 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                    m_creature->SummonCreature(NPC_SMOLDERING_SKELETON, m_creature->GetPositionX()-5,m_creature->GetPositionY(),m_creature->GetPositionZ(), 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                    DoScriptText(WARD_EMOTE_1, m_creature);
                    break;
         }
     }
     void UpdateAI(const uint32 uiDiff)
     {
            if (uiWaveTimer <= uiDiff)
            {
                if(Player *pPlayer = m_creature->GetMap()->GetPlayer(m_creature->GetOwnerGuid()))
                {
                if(pPlayer->GetQuestStatus(QUEST_NO_PLACE_TO_RUN) != QUEST_STATUS_INCOMPLETE)
                         m_creature->ForcedDespawn();
                }
                if(uiWaveCounter == 4)
                {
                    DoScriptText(WARD_EMOTE_2, m_creature);
                    if(Player *pPlayer = m_creature->GetMap()->GetPlayer(m_creature->GetOwnerGuid()))
                    {
                        if(pPlayer->isAlive())
                            pPlayer->KilledMonsterCredit(KILL_CREDIT_BUNNY, m_creature->GetGUID());
                    }
                    m_creature->ForcedDespawn();
                }
                if(uiWaveCounter<=3)
                {
                    SummonWave();
                    uiWaveTimer = 15000;
                    uiWaveCounter++;
                }

            } else uiWaveTimer -= uiDiff;
     }
};

CreatureAI* GetAI_npc_destructive_ward(Creature* pCreature)
{
    return new npc_destructive_wardAI(pCreature);
}

/*######
## npc_ravaged_giant
######*/
enum
{
    QUEST_SLIM_PICKINGS               = 12075,
    ITEM_SAMPLE_OF_ROCKFLESH          = 36765
};

bool GossipHello_npc_ravaged_giant(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if(pPlayer->GetQuestStatus(QUEST_SLIM_PICKINGS ) == QUEST_STATUS_INCOMPLETE)
    {
            ItemPosCountVec dest;
            uint8 msg = pPlayer->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, ITEM_SAMPLE_OF_ROCKFLESH, 1, false);
            if (msg == EQUIP_ERR_OK)
                pPlayer->StoreNewItem(dest, ITEM_SAMPLE_OF_ROCKFLESH, 1, true);
    }
    return true;
}

/*######
## npc_vengeful_geist
######*/

enum
{
    NPC_TRAPPED_VILLAGER             = 27359,
    QUEST_RESCUE_FROM_TOWN_SQUARE    = 12253,
    SPELL_DESPAWN_SELF               = 43014

};

struct MANGOS_DLL_DECL npc_vengeful_geistAI : public ScriptedAI
{
    npc_vengeful_geistAI(Creature* pCreature) : ScriptedAI(pCreature) { Reset(); }
    
    void Reset(){}
    void JustDied(Unit* pKiller)
    {
        if(Creature* pVillager = GetClosestCreatureWithEntry(m_creature, NPC_TRAPPED_VILLAGER, 15.0f))
        { 
            if(Player *pPlayer = m_creature->GetMap()->GetPlayer(pKiller->GetGUID()))
            {
                if(pPlayer->GetQuestStatus(QUEST_RESCUE_FROM_TOWN_SQUARE) == QUEST_STATUS_INCOMPLETE)
                {
                    pPlayer->KilledMonsterCredit(NPC_TRAPPED_VILLAGER);
                    pVillager->CastSpell(pVillager, SPELL_DESPAWN_SELF, false);
                }
            }
        }
    }

};

CreatureAI* GetAI_npc_vengeful_geist(Creature* pCreature)
{
    return new npc_vengeful_geistAI(pCreature);
}
/*######
## npc_inquisitor_hallard
######*/

enum
{
    NPC_MAYOR_GODFREY                = 27577,
    QUEST_RIGHTEOUS_SERMON           = 12321,
    SPELL_INQUISITOR_PENANCE         = 49062,

    HALLARD_SAY_1                    = -1789900,
    HALLARD_SAY_2                    = -1789901,
    GODFREY_EMOTE_1                  = -1789902,
    HALLARD_SAY_3                    = -1789903,
    HALLARD_SAY_4                    = -1789904,
    GODFREY_EMOTE_2                  = -1789905,
    GODFREY_SAY_1                    = -1789906,
    GODFREY_SAY_2                    = -1789907,
    GODFREY_SAY_3                    = -1789908,
    HALLARD_SAY_5                    = -1789909,
    HALLARD_SAY_6                    = -1789927,
    HALLARD_SAY_7                    = -1789910,
    HALLARD_SAY_8                    = -1789911,
    HALLARD_SAY_9                    = -1789912,
    HALLARD_SAY_10                   = -1789913,
    GODFREY_SAY_4                    = -1789914,
    GODFREY_SAY_5                    = -1789915,
    HALLARD_SAY_11                   = -1789916,
    GODFREY_SAY_6                    = -1789917,
    HALLARD_SAY_12                   = -1789918,
    GODFREY_SAY_7                    = -1789919,
    GODFREY_SAY_8                    = -1789920,
    HALLARD_SAY_13                   = -1789921,
    GODFREY_SAY_9                    = -1789922,
    GODFREY_SAY_10                   = -1789923,
    HALLARD_SAY_14                   = -1789924,
    HALLARD_SAY_15                   = -1789925,
    HALLARD_SAY_16                   = -1789926

};

struct MANGOS_DLL_DECL npc_inquisitor_hallardAI : public ScriptedAI
{
    npc_inquisitor_hallardAI(Creature* pCreature) : ScriptedAI(pCreature) { Reset(); }
    
    uint64 uiPlayerGUID;
    uint64 uiEventTimer;
    bool bEventStarted;
    uint32 uiPhase;

     void Reset()
     {
         uiPlayerGUID = 0;
         bEventStarted = false;
         uiPhase = 0;
         uiEventTimer = 2000;
     }
    
     void UpdateAI(const uint32 uiDiff)
     {
         if(bEventStarted)
         {
            if (uiEventTimer <= uiDiff)
            {
                switch(uiPhase)
                {
                    case 0: if(Player *pPlayer = m_creature->GetMap()->GetPlayer(uiPlayerGUID))
                                  DoScriptText(HALLARD_SAY_1 ,m_creature, pPlayer);
                            uiEventTimer = 4000;
                            break;
                    case 1: DoScriptText(HALLARD_SAY_2 ,m_creature); uiEventTimer = 2000; break;
                    case 2: if(Creature *pGodfrey = GetClosestCreatureWithEntry(m_creature, NPC_MAYOR_GODFREY, 15.0f))	
                                DoScriptText(GODFREY_EMOTE_1, pGodfrey);
                            uiEventTimer = 2000; break;
                    case 3: DoScriptText(HALLARD_SAY_3 ,m_creature); uiEventTimer = 4000; break;
                    case 4: DoScriptText(HALLARD_SAY_4 ,m_creature); uiEventTimer = 2000; break;
                    case 5: if(Creature *pGodfrey = GetClosestCreatureWithEntry(m_creature, NPC_MAYOR_GODFREY, 15.0f))	
                                DoScriptText(GODFREY_EMOTE_2, pGodfrey);
                            uiEventTimer = 3000; break;
                    case 6: if(Creature *pGodfrey = GetClosestCreatureWithEntry(m_creature, NPC_MAYOR_GODFREY, 15.0f))	
                                DoScriptText(GODFREY_SAY_1, pGodfrey);
                            uiEventTimer = 5000; break;
                    case 7: if(Creature *pGodfrey = GetClosestCreatureWithEntry(m_creature, NPC_MAYOR_GODFREY, 15.0f))	
                                DoScriptText(GODFREY_SAY_2, pGodfrey);
                            uiEventTimer = 5000; break;
                    case 8: if(Creature *pGodfrey = GetClosestCreatureWithEntry(m_creature, NPC_MAYOR_GODFREY, 15.0f))	
                                DoScriptText(GODFREY_SAY_3, pGodfrey);
                            uiEventTimer = 5000; break;
                    case 9:  DoScriptText(HALLARD_SAY_5 ,m_creature); uiEventTimer = 7000; break; 
                    case 10: DoScriptText(HALLARD_SAY_6 ,m_creature); uiEventTimer = 8000; break;
                    case 11: DoScriptText(HALLARD_SAY_7 ,m_creature); uiEventTimer = 9000; break;
                    case 12: DoScriptText(HALLARD_SAY_8 ,m_creature); uiEventTimer = 9000; break;
                    case 13: if(Creature *pGodfrey = GetClosestCreatureWithEntry(m_creature, NPC_MAYOR_GODFREY, 15.0f))	
                                 m_creature->CastSpell(pGodfrey, SPELL_INQUISITOR_PENANCE,false);
                             DoScriptText(HALLARD_SAY_9 ,m_creature); uiEventTimer = 4000; break;
                    case 14: DoScriptText(HALLARD_SAY_10 ,m_creature); uiEventTimer = 4000; break;
                    case 15: if(Creature *pGodfrey = GetClosestCreatureWithEntry(m_creature, NPC_MAYOR_GODFREY, 15.0f))	
                                 m_creature->CastSpell(pGodfrey, SPELL_INQUISITOR_PENANCE,false);
                             DoScriptText(HALLARD_SAY_9 ,m_creature); uiEventTimer = 4000; break;
                    case 16: if(Creature *pGodfrey = GetClosestCreatureWithEntry(m_creature, NPC_MAYOR_GODFREY, 15.0f))	
                                DoScriptText(GODFREY_SAY_4, pGodfrey);
                            uiEventTimer = 2000; break;
                    case 17: if(Creature *pGodfrey = GetClosestCreatureWithEntry(m_creature, NPC_MAYOR_GODFREY, 15.0f))	
                                DoScriptText(GODFREY_SAY_5, pGodfrey);
                            uiEventTimer = 5000; break;
                    case 18: if(Creature *pGodfrey = GetClosestCreatureWithEntry(m_creature, NPC_MAYOR_GODFREY, 15.0f))	
                                 m_creature->CastSpell(pGodfrey, SPELL_INQUISITOR_PENANCE,false);
                             DoScriptText(HALLARD_SAY_9 ,m_creature); uiEventTimer = 4000; break;
                    case 19: if(Creature *pGodfrey = GetClosestCreatureWithEntry(m_creature, NPC_MAYOR_GODFREY, 15.0f))	
                                DoScriptText(GODFREY_SAY_4, pGodfrey);
                            uiEventTimer = 4000; break;
                    case 20: DoScriptText(HALLARD_SAY_11 ,m_creature); uiEventTimer = 7000; break;
                    case 21: if(Creature *pGodfrey = GetClosestCreatureWithEntry(m_creature, NPC_MAYOR_GODFREY, 15.0f))	
                                DoScriptText(GODFREY_SAY_6, pGodfrey);
                            uiEventTimer = 7000; break;
                    case 22: DoScriptText(HALLARD_SAY_12 ,m_creature); uiEventTimer = 10000; break;
                    case 23: if(Creature *pGodfrey = GetClosestCreatureWithEntry(m_creature, NPC_MAYOR_GODFREY, 15.0f))	
                                DoScriptText(GODFREY_SAY_7, pGodfrey);
                            uiEventTimer = 8000; break;
                    case 24: if(Creature *pGodfrey = GetClosestCreatureWithEntry(m_creature, NPC_MAYOR_GODFREY, 15.0f))	
                                DoScriptText(GODFREY_SAY_8, pGodfrey);
                            uiEventTimer = 8000; break;
                    case 25: DoScriptText(HALLARD_SAY_13 ,m_creature); uiEventTimer = 10000; break;
                    case 26: if(Creature *pGodfrey = GetClosestCreatureWithEntry(m_creature, NPC_MAYOR_GODFREY, 15.0f))	
                                DoScriptText(GODFREY_SAY_9, pGodfrey);
                            uiEventTimer = 7000; break;
                    case 27: if(Creature *pGodfrey = GetClosestCreatureWithEntry(m_creature, NPC_MAYOR_GODFREY, 15.0f))	
                                DoScriptText(GODFREY_SAY_10, pGodfrey);
                            uiEventTimer = 9000; break;
                    case 28: DoScriptText(HALLARD_SAY_14 ,m_creature); uiEventTimer = 10000; break;
                    case 29: if(Player *pPlayer = m_creature->GetMap()->GetPlayer(uiPlayerGUID))
                                DoScriptText(HALLARD_SAY_15 ,m_creature, pPlayer); uiEventTimer = 12000; break;
                    case 30: DoScriptText(HALLARD_SAY_16 ,m_creature); 
                             if(Player *pPlayer = m_creature->GetMap()->GetPlayer(uiPlayerGUID))
                                pPlayer->AreaExploredOrEventHappens(QUEST_RIGHTEOUS_SERMON);
                             m_creature->ForcedDespawn();
                             break;
                    

                } 
                uiPhase++;
            } else uiEventTimer -= uiDiff;
         }
     }

};

CreatureAI* GetAI_npc_inquisitor_hallard(Creature* pCreature)
{
    return new npc_inquisitor_hallardAI(pCreature);
}

bool QuestAccept_npc_inquisitor_hallard(Player* pPlayer, Creature* pCreature, const Quest* pQuest)
{
    switch(pQuest->GetQuestId())
    {
        case QUEST_RIGHTEOUS_SERMON:
        {
            if (npc_inquisitor_hallardAI* pHallardAI = dynamic_cast<npc_inquisitor_hallardAI*>(pCreature->AI()))
            {
                pCreature->GetMotionMaster()->MovePoint(0, 3801.38f , -679.13f , 213.73f );
                pHallardAI->bEventStarted = true;
                pHallardAI->uiPlayerGUID = (pPlayer->GetGUID());
            }
        }
        break;
    }
    return true;
}

/*######
## npc_wintergarde_bomb
######*/
enum 
{
    NPC_UPPER_MINE_SHAFT            = 27436,
    NPC_LOWER_MINE_SHAFT            = 27437,
    QUEST_LEAVE_NOTHING_TO_CHANCE   = 12277
 
};

struct MANGOS_DLL_DECL npc_wintergarde_bombAI : public ScriptedAI
{
    npc_wintergarde_bombAI(Creature* pCreature) : ScriptedAI(pCreature) { Reset(); }

    uint32 uiCheckTimer;
    void Reset() 
    {
        uiCheckTimer = 2000;
    }

    void UpdateAI(const uint32 uiDiff)
     {
            if (uiCheckTimer <= uiDiff)
            {
                if(Player *pPlayer = m_creature->GetMap()->GetPlayer(m_creature->GetCreatorGuid()))
                {
                    if(pPlayer->GetQuestStatus(QUEST_LEAVE_NOTHING_TO_CHANCE) == QUEST_STATUS_INCOMPLETE)
                    {
                        if (m_creature->GetPositionZ() < 118.0f)
                            pPlayer->KilledMonsterCredit(NPC_LOWER_MINE_SHAFT);
                        else pPlayer->KilledMonsterCredit(NPC_UPPER_MINE_SHAFT);
                    }
                    m_creature->ForcedDespawn();
                }                
            } else uiCheckTimer -= uiDiff;
     }    
};
CreatureAI* GetAI_npc_wintergarde_bomb(Creature* pCreature)
{
    return new npc_wintergarde_bombAI(pCreature);
}

void AddSC_dragonblight()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "npc_afrasastrasz";
    newscript->pGossipHello = &GossipHello_npc_afrasastrasz;
    newscript->pGossipSelect = &GossipSelect_npc_afrasastrasz;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_alexstrasza_wr_gate";
    newscript->pGossipHello = &GossipHello_npc_alexstrasza_wr_gate;
    newscript->pGossipSelect = &GossipSelect_npc_alexstrasza_wr_gate;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_tariolstrasz";
    newscript->pGossipHello = &GossipHello_npc_tariolstrasz;
    newscript->pGossipSelect = &GossipSelect_npc_tariolstrasz;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_torastrasza";
    newscript->pGossipHello = &GossipHello_npc_torastrasza;
    newscript->pGossipSelect = &GossipSelect_npc_torastrasza;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_abbey_bell_rope";
    newscript->pGOUse = &GOUse_go_abbey_bell_rope;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_abbot_landgren";
    newscript->pGossipHello = &GossipHello_npc_abbot_landgren;
    newscript->pGossipSelect = &GossipSelect_npc_abbot_landgren;
    newscript->RegisterSelf();
    
    newscript = new Script;
    newscript->Name = "npc_abbot_to_escort";
    newscript->GetAI = &GetAI_npc_abbot_to_escort;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_maggot";
    newscript->GetAI = &GetAI_mob_maggot;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_hourglass";
    newscript->GetAI = &GetAI_npc_hourglass;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_vehicle";
    newscript->GetAI = &GetAI_npc_vehicle;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_destructive_ward";
    newscript->GetAI = &GetAI_npc_destructive_ward;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_ravaged_giant";
    newscript->pGossipHello = &GossipHello_npc_ravaged_giant;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_vengeful_geist";
    newscript->GetAI = &GetAI_npc_vengeful_geist;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_inquisitor_hallard";
    newscript->GetAI = &GetAI_npc_inquisitor_hallard;
    newscript->pQuestAcceptNPC = &QuestAccept_npc_inquisitor_hallard;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_wintergarde_bomb";
    newscript->GetAI = &GetAI_npc_wintergarde_bomb;
    newscript->RegisterSelf();
}
