-- Fingers of Frost: proc from frost spells including Frostfire bolt and Ice/Frost Armor
-- NOTE: proc chance doesn't work for rank2, it is taken from rank1
DELETE FROM `spell_proc_event` WHERE `entry` IN (44543,44545);
INSERT INTO `spell_proc_event` VALUES
(44543,0,3,0x021002A0,0x021002A0,0x021002A0,0x1000,0,0,0,0,0,0,0,0,7,0),
(44545,0,3,0x021002A0,0x021002A0,0x021002A0,0x1000,0,0,0,0,0,0,0,5,15,0);
