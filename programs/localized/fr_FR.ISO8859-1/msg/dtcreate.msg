$ $TOG: dtcreate.msg /main/4 1999/09/17 17:23:37 mgreess $
$ %Z%%M%        %I%  %W% %G% %U%  
$   
$   COMPONENT_NAME: dtcreate  
$   
$   FUNCTIONS: none  
$   
$   ORIGINS: 27  
$   
$   
$   (C) COPYRIGHT International Business Machines Corp. 1993  
$   All Rights Reserved  
$   Licensed Materials - Property of IBM  
$   US Government Users Restricted Rights - Use, duplication or  
$   disclosure restricted by GSA ADP Schedule Contract with IBM Corp.  
$   
$ **   Description:  
$ **   ------------  
$ **   This is the source message catalog file for dtcreate.  
$quote "

$set 2
$ *****************************************************************************  
$ **  
$ ** Message set for menu options on main window  
$ **  
$ *****************************************************************************  

10 "Fichier"

11 "F"

15 "Ouvrir..."

16 "O"

20 "Nouveau"

21 "N"

25 "Sauvegarder"

26 "S"

30 "Quitter"

31 "Q"

35 "Options"

36 "O"

40 "Affich. fonctions �tendues"

41 "A"

42 "Afficher ic�nes"

43 "i"

44 "Couleur"

46 "C"

47 "Monochrome"

48 "M"

49 "Affich. ic�nes monochromes"

50 "m"

53 "Aide"

54 "A"

60 "G�n�ralit�s"

61 "G"

65 "Table des mati�res"

66 "T"

70 "T�ches"

71 "c"

75 "R�f�rence"

76 "R"

80 "Aide sur l'aide"

81 "i"

85 "A propos de l'application"

86 "p"

$set 3        Redefine set#

$ *****************************************************************************  
$ **  
$ ** Message set for  main Create Action window  
$ **  
$ *****************************************************************************  

10 "Cr�er une action"

12 "Nom (libell� de l'ic�ne):"

13 "Ic�nes d'action:"

20 "Commande ex�cut�e lors du double-clic:"

21 "Commande ex�cut�e lors du double-clic:"

22 "Commande ex�cut�e � l'ouverture de l'action:"

30 "Aide sur l'ic�ne:"

32 "Type de fen�tre:"

34 "Graphique (X-Window)"

36 "Terminal (fermeture auto.)"

38 "Terminal (fermeture manuelle)"

40 "Pas de sortie"

50 "Avanc�e"

52 "De base"

$set 4        Redefine set#

$ *****************************************************************************  
$ **  
$ ** Message set for  main Create Action window advanced function area  
$ **  
$ *****************************************************************************  

10 "En option"

11 "A l'ouverture de l'action, demander aux utilisateurs:"

12 "Types de donn�es utilisant l'action:"

13 "Ajouter..."

14 "Supprimer"

15 "Editer..."

16 "Types de donn�es pouvant �tre pos�s:"

17 "Tous"

18 "Liste ci-dessus seulement"

$set 5        Redefine set#

$ *****************************************************************************  
$ **  
$ ** Error and Information message set for  main Create Action window  
$ **  
$ *****************************************************************************  

10 "Le nom de l'action est manquant: indiquez-le\n\
dans la zone Nom (libell� de l'ic�ne)."
$   

15 "La commande � ex�cuter est manquante:\n\
indiquez-la dans la zone Commande\n\
ex�cut�e � l'ouverture de l'action."
$   

20 "La liste Types de donn�es utilisant l'action est\n\
vide. Or, vous avez s�lectionn� Liste ci-dessus\n\
seulement dans la zone Types de donn�es pouvant �tre\n\
pos�s. Modifiez votre s�lection en Tous types de donn�es\n\
ou ajoutez au moins un type de donn�es � la liste."
$   

25 "Une action et un fichier de d�finition sont d�j�\n\
associ�s � ce nom d'action.\n\
Vous pouvez annuler la sauvegarde et modifier le nom\n\
de l'action ou remplacer le fichier de d�finition\n\
existant. Confirmez-vous le remplacement ?"
$   

30 "La zone Commande ex�cut�e � l'ouverture de l'action\n\
ne comporte aucun nom de variable. Indiquez-en un\n\
correspondant au libell� sp�cifi� dans la zone\n\
A l'ouverture de l'action, demander aux utilisateurs:.\n\
Les noms admis sont: $*, $1, $2, ..., $9."
$   

35 "Les modifications n'ont pas �t� sauvegard�es.\n\
Voulez-vous effectuer la sauvegarde avant de sortir ?"
$   

40 "Les modifications n'ont pas �t� sauvegard�es.\n\
Voulez-vous sauvegarder cette action avant\n\
d'en cr�er une autre ?"
$   

45 "Les modifications n'ont pas �t� sauvegard�es.\n\
Voulez-vous effectuer la sauvegarde avant de\n\
charger un autre fichier de d�finition d'action ?"
$   

50 "Le nom d'action contient un ou plusieurs\n\
caract�res incorrects.\n\
Les caract�res suivants ne sont pas autoris�s:\n\
  / \ \" ' ;  (  ) ~ ! $ { } < > # @ | &"
$   

55 "Impossible de cr�er le fichier suivant:"
$   

60 "Impossible d'ouvrir le fichier suivant:"
$   

65 "Le fichier suivant n'a pas pu �tre charg� car il n'a pas\n\
�t� cr�e � l'aide de l'utilitaire de cr�ation d'action."
$   

66 "Le fichier n'a pas pu �tre charg� car il n'a pas �t� modifi� � l'aide\n\
de l'utilitaire de cr�ation d'action. Il est possible que cette op�ration\n\
ait �t� effectu�e par l'interm�diaire d'un �diteur de texte, par exemple."
$   

67 "L'utilitaire de cr�ation d'action ne permet de\n\
modifier que les fichiers cr��s par son interm�diaire."
$   

68 "Impossible de charger le fichier suivant:"
$   
$  The following messages are all part of the same message dialog  

70 "La nouvelle action"

71 "a �t� plac�e dans votre dossier personnel."

73 "Le fichier de d�finition d'action cr�� s'appelle:"
$   

80 "Impossible de trouver toutes les dimensions de\n\
l'ic�ne s�lectionn�e."
$   

85 "Impossible de lancer l'�diteur d'ic�nes."
$   

90 "Impossible d'analyser le fichier suivant:"
$   

95 "Le fichier d'ic�ne suivant est introuvable\n\
dans le chemin de recherche."
$   

98 "L'ic�ne s�lectionn�e ne figure pas dans le chemin de\n\
recherche. Vous devez la placer dans un r�pertoire figurant\n\
dans ce chemin, afin qu'elle s'affiche correctement dans\n\
l'environnement de l'espace de travail.\n\
Pour utiliser l'ic�ne, s�lectionnez OK.\n\
Pour choisir une ic�ne diff�rente, s�lectionnez Annuler."
$   
$ ONLY TRANSLATE  "Usage"  and  "filename"  

110 "Syntaxe: dtcreate [<nom_fichier>] [-?]"
$   

120 "Vous n'avez pas s�lectionn� de type de donn�es\n\
dans la liste Types de donn�es utilisant l'action."

125 "S�lectionnez le type de donn�es � supprimer."

130 "S�lectionnez le type de donn�es � �diter."
$   

150 "Le travail en cours n'a pas �t� sauvegard�."

152 "Ne pas sauvegarder"

154 "Annuler fermeture"
$   

160 "Impossible de sauvegarder la session dans le fichier:"

162 "Impossible de restaurer le fichier � partir du fichier:"
$   
$ TRANSLATORS: DO NOT TRANSLATE the word "HOME" in the following message  

170 "La variable d'environnement HOME n'est pas d�finie.\n\
Cette variable doit �tre d�finie pour que l'action\n\
puisse �tre sauvegard�e."

$set 6        Redefine set#

$ *****************************************************************************  
$ **  
$ ** General message set for dialogs  
$ **  
$ *****************************************************************************  

10 "OK"

11 "Appliquer"

12 "Annuler"

13 "Aide"

14 "Effacer"

18 "Rechercher"

19 "Rech. ensemble"

20 "Editer une ic�ne..."

31 "Cr�er une action - Erreur"

41 "Cr�er une action - Confirmation"

46 "Cr�er une action - Informations"

51 "Cr�er une action - Question"

$set 7        Redefine set#

$ *****************************************************************************  
$ **  
$ ** Message set for Add Datatype and Edit Datatype dialogs  
$ **  
$ *****************************************************************************  

10 "Ajouter un type de donn�es"

11 "Editer un type de donn�es"

14 "Nom de la famille du type de donn�es:"

15 "Caract�ristiques:"

16 "Editer..."

17 "Aide sur l'ic�ne de type de donn�es:"

18 "Ic�nes du type de donn�es:"

21 "Commandes"

22 "Commande d'ouverture du type de donn�es:"

23 "Commande d'impression du type de donn�es:"

30 "Ouvrir"

31 "Imprimer"

$set 8        Redefine set#

$ *****************************************************************************  
$ **  
$ ** Error and Information message set for  
$ **    Add Datatype and Edit Datatype dialogs  
$ **  
$ *****************************************************************************  

10 "Le nom de la famille du type de donn�es est manquant.\n\
Indiquez-le dans la zone correspondante."
$   

15 "Les caract�ristiques d'identification sont manquantes:\n\
vous devez les indiquer pour que le type de donn�es\n\
puisse �tre cr��. Pour ce faire, s�lectionnez le bouton\n\
Editer en regard de la liste Caract�ristiques."
$   

20 "La zone Nom de la famille de type de donn�es\n\
contient un ou plusieurs caract�res incorrects.\n\
Les caract�res suivants ne sont pas autoris�s:\n\
  / \ \" ' ;  (  ) ~ ! $ { } < > # @ | &"
$   

25 "Ce nom est d�j� utilis� pour une famille de type de\n\
donn�es. Modifiez-le dans la zone Nom de la famille\n\
du type de donn�es."

$set 9        Redefine set#

$ *****************************************************************************  
$ **  
$ ** Message set for  Identifying Characteristics dialog  
$ **  
$ *****************************************************************************  

10 "Caract�ristiques"

11 "Tout inclure"

12 "Fichiers"

13 "Dossiers"

14 "correspondant aux crit�res suivants:"

20 "Mod�le de nom:"

21 "Mod�le d'autorisations:"

22 "Accessible en lecture"

24 "Acessible en �criture"

25 "Ex�cutable"

27 "ET"

28 "Contenu"

29 "Mod�le:"

30 "Type de donn�es:"

31 "Cha�ne"

32 "Octets (hex)"

33 "Courtes (d�cimales)"

34 "Longues (d�cimales)"

35 "Octet de d�part:"

40 "Lecture:"

41 "Ecriture:"

42 "Ex�cution:"

43 "En fonction"

44 "Hors fonction"

45 "Indiff�remment"

$set 10        Redefine set#

$ *****************************************************************************  
$ **  
$ ** Error and Information message set for Identifying Characteristics dialog  
$ **  
$ *****************************************************************************  

10 "Le mod�le de nom est manquant.\n\
Si vous s�lectionnez Mod�le de nom,\n\
vous devez compl�ter cette zone."
$   

15 "Les autorisations sont manquantes.\n\
Si vous s�lectionnez Mod�le d'autorisations,\n\
vous devez s�lectionner une ou plusieurs\n\
options sous Mod�le d'autorisations."
$   

20 "Le mod�le de contenu est manquant. Si vous s�lectionnez\n\
Contenu comme caract�ristique, la zone Mod�le\n\
figurant sous cette option doit �tre compl�t�e."
$   

25 "La valeur d'octet de d�but est manquante.\n\
Si Contenu est s�lectionn�, un nombre\n\
doit �tre indiqu� dans la zone Octet de d�but."
$   

30 "Vous n'avez s�lectionn� aucune caract�ristique.\n\
Vous devez s�lectionner Mod�le de nom, Mod�le \n\
d'autorisations ou Contenu."
$   

45 "Le mod�le de nom contient un ou plusieurs\n\
caract�res incorrects.\n\
Les caract�res suivants ne sont pas autoris�s:\n\
  / \ \" ' ;  (  ) ~ ! $ { } < > # @ | &"
$   

46 "Le Mod�le de contenu n'est pas compatible\n\
avec le format de type de contenu s�lectionn�.\n\
Corrigez le format ou modifiez le type de sorte\n\
qu'il corresponde au mod�le de contenu."
$   

47 "La zone Octet de d�but contient des caract�res incorrects.\n\
Seuls les nombres d�cimaux sont admis."
$   

48 "Si vous utilisez le mod�le de contenu, les performances\n\
du Gestionnaire de fichiers risquent d'�tre ralenties.\n\
En effet, celui-ci recherche le contenu de tous les\n\
fichiers dans un dossier avant d'ouvrir ce dernier.\n\
L'ouverture des dossiers est donc plus lente. \n\
Il est conseill� d'utiliser uniquement les mod�les\n\
de nom et d'autorisations."

$set 11        Redefine set#

$ *****************************************************************************  
$ **  
$ ** Message set for  Icon Selection Dialog  
$ **  
$ *****************************************************************************  

10 "R�pertoires"

11 "Fichiers d'ic�nes"

12 "Entrez un nom de fichier d'ic�ne"

20 "Chargement en cours des ic�nes. Veuillez patienter."

30 "Dossiers d'ic�nes"

50 "Le fichier d'ic�ne indiqu� est incorrect.\n\
Corrigez-le dans la zone Entrez un nom\n\
de fichier d'ic�ne."
$ ONLY TRANSLATE  "Empty".   Do not translate the brackets "[" and "]".  

60 "[Vide]"

$set 12        Redefine set#

$ *****************************************************************************  
$ **  
$ ** Message set for  Open File Dialog  
$ **  
$ *****************************************************************************  

10 "Filtre"

11 "R�pertoires"

12 "Fichiers"

13 "S�lection"

20 "Ouvrir un fichier"

25 "Cr�er une action - Ouverture"

$set 13
$ *****************************************************************************
$ **
$ ** Message set for  DieFromToolTalkError Dialog
$ **
$ *****************************************************************************
$ These are the messages for the ToolTalk error dialog
$ "-NEW"
1 Create Action - Error
$ "-NEW"
2 "Could not connect to ToolTalk:\n%s\nExiting ..."
$ "-NEW"
3 OK
