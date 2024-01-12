EXEMPLE:
NO ./textures/Brique-rouge.xpm
SO ./textures/Pierres-moussues.xpm
WE ./textures/Pierres.xpm
EA ./textures/Pierres-claires.xpm
F 220,100,0
C 225,30,0

 1111 
1E0101
100001
110001
 1111

Erreurs à tester :

TEXTURES:
NO ./textures/test.xpm							// Fichier de texture vide
	--> Se lance et se referme - map09.cub
NO ./textures/Brique-rouge.xp					// Format non .xpm
NO ./textures/Brique-roue.xpm					// Erreur dans nom du fichier texture .xpm
NO 												// Aucune texture (avec espace)
NO												// Aucune texture (sans espace)
\0												// Aucune texture (sans direction)
Texture après la map
Textures en double


COULEUR:
RGB > 255
RGB < 0
RGB '.' au lieu de ',' / ou -RGB
RGB avec un couleur en moins (ex: C 225,111)
RGB avec un couleur en moins (ex: C 225,111, )
	--> Fonctionne ?


PERSONNAGE:
Absence de personnage
Trop de personnages
Personnage en dehors de la map
Personnage à la place d'un mur


MAP:
Chiffre autre que 1 et 0 dans la map
Map séparée par des espaces (non fermée)
Deux maps (fermées) séparées par des espaces
