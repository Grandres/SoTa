-- Support for quest Lefty Loosey, Righty Tighy

DELETE FROM creature WHERE id IN(25830,25832,25833,25831);
DELETE FROM event_scripts WHERE id IN(16909,16904,17208,17207);
INSERT INTO event_scripts (id,delay,command,datalong,datalong2,x,y,z,o) VALUES
(16909,2,10,25831,30000,4225.62,4800.58,-11.673,-2.84488),
(17207,2,10,25832,30000,4032.6,4900.22,-11.2077,-0.820303),
(17208,2,10,25833,30000,3791.71,4801.95,-11.5423,4.59119),
(16904,2,10,25830,30000,4114.85,5098.89,0.02471,-2.60053);
