$ $XConsortium: dtksh.msg /main/3 1995/12/08 09:23:38 rswiston $
$quote "

$set 1

1 "DtkshCvtStringToPixel: La couleur '%s' n'est pas d�finie."

$set 5        Redefine set#


1 "Les param�tres de ressources indiqu�s sont trop nombreux ; '%s' n'est pas pris en compte."

2 "Sp�cification de ressource incorrecte. La forme admise est 'nom:valeur' : %s"

3 "Le s�parateur de ressource est ':'. Or, vous avez utilis� '=' : %s"

4 "La bo�te � outils a d�j� �t� initialis�e."

5 "Syntaxe: XtInitialize variable nom_application classe_application [arg. ...]"

6 "Syntaxe: %s variable nom classe parent [arg:val ...]"

7 "Syntaxe: XtCreateApplicationShell variable nom classe [arg:val ...]"

8 "Syntaxe: XtPopup widget GrabNone|GrabNonexclusive|GrabExclusive"

9 "Le type d'appropriation '%s' est inconnu ; utilisation de 'GrabNone'."

10 "Syntaxe: XtIsShell widget"

11 "Syntaxe: XtMapWidget widget"

12 "Syntaxe: XtUnmapWidget widget"

13 "Syntaxe: %s variable widget"

14 "Syntaxe: XtScreen variable widget"

15 "Syntaxe: XtWindow variable widget"

16 "Syntaxe: XtCallCallbacks widget fonction_appel�e"

17 "Syntaxe: XtHasCallbacks variable widget fonction_appel�e"

18 "Syntaxe: XtAddCallback widget fonction_appel�e commande_ksh"

19 "Syntaxe: XtRemoveCallback widget fonction_appel�e commande_ksh"

20 "Le descripteur de fonction appel�e suivant est incorrect: %s"

21 "La fonction appel�e indiqu�e n'est pas enregistr�e."

22 "Syntaxe: XtAddEventHandler widget masque masque_impossible command_ksh"

23 "Syntaxe: XtRemoveEventHandler widget masque masque_impossible commande_ksh"

24 "Le descripteur d'�v�nement indiqu� n'est pas enregistr�."

25 "Syntaxe: XtGetValues widget ressource:variable ..."

26 "La forme du param�tre de ressource suivant est incorrecte: %s."

27 "Syntaxe: XtSetValues widget arg:val ..."

28 "Syntaxe: XtAddWorkProc variable commande"

29 "Syntaxe: XtRemoveWorkProc ID_proc_travail"

30 "Un nombre hexad�cimal doit �tre indiqu� pour le param�tre ID_proc_travail: %s"

31 "Syntaxe: XtAddTimeOut variable millisecondes commande"

32 "La valeur indiqu�e pour le param�tre millisecondes doit �tre sup�rieure � z�ro."

33 "Syntaxe: XtRemoveTimeOut ID_intervalle"

34 "Un nombre hexad�cimal doit �tre indiqu� pour le param�tre ID_intervalle: %s"

35 "Syntaxe: %s widget ..."

36 "Syntaxe: XBell affichage volume"

37 "Syntaxe: %s variable �cran"

38 "Le param�tre d'�cran est incorrect: %s"

39 "Syntaxe: XDefineCursor affichage fen�tre ID_curseur"

40 "Le param�tre ID_curseur est incorrect: %s"

41 "Syntaxe: XUndefineCursor affichage fen�tre"

42 "Syntaxe: XtRemoveAllCallbacks widget fonction_appel�e"

43 "Syntaxe: XTextWidth variable nom_police cha�ne"

44 "Syntaxe: %s affichage zone_dessin [arg. ...]"

45 "Le param�tre zone_dessin est incorrect: %s"

46 "Le param�tre cible est incorrect: %s"

47 "Nom de fonction graphique inconnu: %s"

48 "Style de ligne inconnu: %s"

49 "Option de dessin inconnue: %s"

50 "Des points n'ont pas �t� pris en compte."

51 "Syntaxe: XCopyArea affichage source cible sourceX sourceY largeur hauteur cibleX cibleY [arg. ...]"

52 "Impossible de convertir le type de ressource '%s' en 'cha�ne'"

53 "Impossible de convertir le type de ressource 'cha�ne' au type '%s'"

54 "Syntaxe: XtAddInput variable [-r] descripteur_fich commande_ksh"

56 "Syntaxe: XtRemoveInput ID_entr�e"

57 "Le param�tre ID_entr�e doit �tre un nombre hexad�cimal: %s"

59 "Syntaxe: XFlush affichage"

60 "Syntaxe: XSync affichage suppression"

61 "Syntaxe: XRaiseWindow affichage fen�tre"

62 "Syntaxe: %s widget [True|False]"

63 "Syntaxe: %s widget translations"

64 "Syntaxe: XtUninstallTranslations widget"

65 "Syntaxe: XtParent variable widget"

66 "Syntaxe: XtLastTimestampProcessed variable affichage"

67 "Syntaxe: DtSessionRestorePath widget variable_chemin fich_sauvegarde"

68 "Syntaxe: DtSessionSavePath widget variable_chemin variable_fichier"

69 "Syntaxe: DtShellIsIconified widget"

70 "Syntaxe: DtSetStartupCommand widget commande"

71 "Syntaxe: DtSetIconifyHint widget bool�en"

73 "Le param�tre fen�tre_root est incorrect: %s"

74 "Syntaxe: DtWsmSetCurrentWorkspace widget atome"

75 "L'atome de l'espace de travail est incorrect: %s"

78 "Syntaxe: DtWsmSetWorkspacesOccupied affichage fen�tre Liste_espaces_travail"

79 "Syntaxe: DtGetHourGlassCursor variable affichage"

80 "Syntaxe: DtWsmAddCurrentWorkspaceCallback variable widget commande_ksh"

81 "Syntaxe: DtWsmRemoveWorkspaceCallback identificateur"

82 "Syntaxe: XtNameToWidget variable widget_r�f�rence noms"

83 "Syntaxe: DtDbLoad"

84 "Syntaxe: DtDbReloadNotify commande_ksh"

85 "Syntaxe: DtActionExists nom_action"

86 "Syntaxe: DtActionLabel variable nom_action"

87 "Syntaxe: DtActionDescription variable nom_action"

88 "Syntaxe: DtActionInvoke widget nom_action param_terminal h�te_ex�c r�p_contexte indic_util commande_ksh [\"FILE\" nom_fichier] ..."

89 "Syntaxe: DtDtsLoadDataTypes"

90 "Syntaxe: DtDtsFileToDataType variable nom_fichier"

91 "Syntaxe: DtDtsFileToAttributeValue variable nom_fichier nom_attribut"

92 "Syntaxe: DtDtsFileToAttributeList variable nom_fichier"

93 "Syntaxe: DtDtsDataTypeToAttributeValue variable type_donn�es nom_attribut nom_option"

94 "Syntaxe: DtDtsDataTypeToAttributeList variable type_donn�es nom_options"

95 "Syntaxe: DtDtsFindAttribute variable nom valeur"

96 "Syntaxe: DtDtsDataTypeNames variable"

97 "Syntaxe: DtDtsSetDataType variable nom_fichier type_donn�es annulation"

98 "Syntaxe: DtDtsDataTypeIsAction type_donn�es"

99 "Syntaxe: ouvert_ttdt variable �tat variable2 nom_outil fournisseur version lancement_envoi"

100 "Syntaxe: gest_entr�e_tttk ID_processus source ID"

101 "Le param�tre source doit �tre un entier: %s"

102 "Le param�tre ID doit �tre un nombre hexad�cimal: %s"

103 "Syntaxe: fern_ttdt �tat ID_processus nouv_ID_processus arr�t_envoi"

104 "Syntaxe: jonction_sessions_ttdt variable �tat ID_session Desc_widget_shell jonction"

105 "Syntaxe: sortie_session_ttdt �tat ID_session mod�les_session sortie"

106 "Le param�tre mod�les_session est incorrect: %s"

107 "Syntaxe: �v�nement_fichier_ttdt �tat op mod�les envoi"

108 "Syntaxe: sortie_fichier_ttdt �tat mod�les sortie"

109 "Syntaxe: modif_ttdt chemin_acc�s port�e d�lai"

110 "Syntaxe: %s �tat chemin_acc�s port�e d�lai"

112 "Syntaxe: pointeur_erreur_tt variable �tat_tt"

113 "Syntaxe: %s �tat msg"

114 "Syntaxe: %s �tat msg �tat_msg cha�ne_�tat_msg suppression"

115 "Syntaxe: jonction_fichiers_ttdt variable �tat chemin_acc�s port�e jonction commande_ksh"

116 "Syntaxe: fich_r�s_fich_tt variable �tat nom_fichier"

117 "Syntaxe: fich_fich_r�seau_tt variable �tat nom_fich_r�seau"

118 "Syntaxe: fich_r�s_fich_h�te_tt variable �tat h�te nom_fichier"

119 "Syntaxe: fich_fich_r�s_h�te_tt variable �tat h�te nom_fich_r�s"

120 "Syntaxe: XtIsSubclass widget classe"

121 "%s n'est pas un nom de classe de widget valide."

122 "Syntaxe: XtClass variable widget"

$set 6        Redefine set#


1 "DtkshCvtWindowToString: La taille de la valeur source est incorrecte."

2 "DtkshCvtHexIntToString: La taille de la valeur source est incorrecte."

3 "DtkshCvtIntToString: La taille de la valeur source est incorrecte."

4 "DtkshCvtBooleanToString: La taille de la valeur source est incorrecte."

5 "DtkshCvtStringToWidget: La taille de la valeur source est incorrecte."

6 "DtkshCvtStringToWidget: Le widget '%s' n'existe pas."

7 "DtkshCvtStringToCallback: La taille de la valeur source est incorrecte."

8 "DtkshCvtCallbackToString: La taille de la valeur source est incorrecte."

9 "DtkshCvtWidgetToString: La taille de la valeur source est incorrecte."

10 "DtkshCvtWidgetToString: Impossible de trouver un nom pour le widget."

11 "DtkshCvtWidgetClassToString: La taille de la valeur source est incorrecte."

12 "DtkshCvtWidgetClassToString: Classe de widget inconnue."

13 "DtkshCvtStringToWidgetClass: Classe de widget inconnue."

14 "DtkshCvtScreenToString: La taille de la valeur source est incorrecte."

$set 11        Redefine set#


1 "La structure '%s' ne contient pas la zone '%s'."

2 "DtkshCvtCallbackToString: D�passement de capacit� d'une m�moire tampon de conversion interne."

3 "Le hachage de la ressource '%s' dans la classe de widget '%s' n'a pas abouti."

4 "Aucun nom de fonction n'a �t� indiqu�."

5 "L'ex�cution de la commande est impossible car la bo�te � outils n'a pas �t� initialis�e."

6 "La cr�ation du widget '%s' n'a pas abouti."

7 "Le param�tre affichage est incorrect: %s"

8 "L'atome de propri�t� suivant est incorrect: %s"

9 "La ressource suivante n'est pas d�finie pour le widget '%s': %s"

10 "La position indiqu�e est incorrecte: %s"

11 "La police indiqu�e est incorrecte: %s"

12 "Le descripteur de widget '%s' n'est pas associ� � un widget existant."

13 "Le widget doit �tre de type 'command'."

14 "Le widget doit �tre de type 'mainWindow'."

15 "Le widget doit �tre de type 'scale'."

16 "Le widget doit �tre de type 'scrollBar'."

17 "Il doit s'agir d'un widget ou d'un gadget de type 'toggleButton'."

18 "Le param�tre de fen�tre est incorrect: %s"

19 "Impossible d'allouer la m�moire requise ; abandon."

20 "Impossible de trouver le widget p�re."

21 "Impossible de localiser le symbole '%s'."

22 "Impossible de localiser le type '%s'."

23 "Impossible d'analyser la d�claration '%s' ; utilisation de 'unsigned long'."

24 "Type de fils inconnu: %s."

25 "Option inconnue: %s."

26 "Syntaxe: %s widget position"

27 "Syntaxe: %s widget heure"

28 "Syntaxe: %s widget"

29 "dtksh - Erreur"

30 "dtksh - Avertissement"

31 "Syntaxe: %s affichage fen�tre"

32 "Syntaxe: %s affichage fen�tre variable"

33 "Syntaxe: %s affichage fen�tre_root variable"

34 "Le param�tre d�lai est incorrect: %s."

35 "Le param�tre msg est incorrect: %s."

36 "Le param�tre mod�les est incorrect: %s."

$set 14        Redefine set#


1 "Une erreur li�e � la table de hachage interne s'est produite lors de l'initialisation de la classe de widget ; abandon."

2 "La classe de widget '%s' n'existe pas."

3 "L'identificateur '%s' n'est pas un descripteur de widget correct."

4 "Classe de widget incorrecte."

5 "Syntaxe: DtLoadWidget nom_classe_widget nom_enreg_classe_widget"

6 "L'enregistrement de classe de widget '%s' est introuvable."

7 "Une erreur li�e � la table de hachage interne s'est produite lors de l'initialisation de la classe de widget '%s'."

8 "\n\
%sRESSOURCES POUR %s%s%s:\n"

9 "CONTRAINTE "

10 "R"

11 "M"

12 "S"

13 "%-15s %-6s %-6s %-18s %-6s %s\n"

14 "VARIABLE ENV    CLASSE MERE DESCRIPT.            NOM ETAT\n"

15 "\n\
Syntaxe:\tDtWidgetInfo [descript_widget]\n\
\tDtWidgetInfo -r <descript_widget|nom_classe>\n\
\tDtWidgetInfo -R <descript_widget|nom_classe>\n\
\tDtWidgetInfo -c [nom_classe]\n\
\tDtWidgetInfo -h [descript_widget]"

$set 15        Redefine set#


1 "Impossible d'initialiser la bo�te � outils."

2 "La ressource suivante ne peut pas �tre d�finie lors de la cr�ation\n\
du widget. Une fois le widget cr��, utilisez XtSetValues: %s"

3 "Syntaxe: %s variable parent nom [argument:valeur ...]"

4 "Syntaxe: DtHelpReturnSelectedWidgetId variable widget variable"

5 "Syntaxe: DtHelpSetCatalogName nom_catalogue"

6 "Syntaxe: DtHelpQuickDialogGetChild variable widget_quickHelp fils"

7 "Le widget doit �tre de type 'quickHelp'."

8 "Le widget doit �tre de type 'list'."

9 "Syntaxe: %s widget position �l�ment"

10 "Syntaxe: %s widget position liste_�l�ments"

11 "Syntaxe: %s widget �l�ment"

12 "Syntaxe: XmListDeleteItemsPos widget nombre position"

13 "Syntaxe: XmListDeleteItems widget liste_�l�ments"

14 "Syntaxe: XmListDeletePositions widget liste_positions"

15 "Syntaxe: XmListGetKbdItemPos variable widget"

16 "Syntaxe: XmListItemExists widget �l�ment"

17 "Syntaxe: XmListItemPos variable widget �l�ment"

18 "Syntaxe: XmListPosSelected widget position"

19 "Syntaxe: XmListPosToBounds widget position variable variable variable variable"

20 "Syntaxe: %s widget position option_notification"

21 "Syntaxe: %s widget �l�ment option_notification"

22 "Syntaxe: XmListSetAddMode widget bool�en"

23 "Syntaxe: XmListSetKbdItemPos widget position"

24 "Syntaxe: XmMainWindowSetAreas fen�tre_principale menu commande d�fil_hor d�fil_vert travail"

25 "Le descripteur 'fen�tre_principale' est NULL."

26 "Syntaxe: %s variable fen�tre_principale"

27 "Syntaxe: XmProcessTraversal widget sens"

28 "Sens de passage inconnu: %s."

29 "Syntaxe: XmInternAtom variable affichage nom existant_seulement"

30 "Syntaxe: XmGetAtomName variable affichage atome"

31 "L'atome indiqu� est incorrect: %s."

32 "Syntaxe: XmGetColors widget arri�re-plan avant-plan ombrage_sup ombrage_inf s�lection"

33 "Pixel d'arri�re-plan incorrect: %s"

34 "Syntaxe: XmUpdateDisplay widget"

35 "Syntaxe: %s widget protocole [protocole ...]"

36 "L'atome indiqu� est incorrect: %s."

37 "Syntaxe: XmAddWMProtocolCallback widget protocole commande_ksh"

38 "Syntaxe: XmRemoveWMProtocolCallback widget protocole commande_ksh"

39 "Syntaxe: XmMenuPosition menu �v�nement"

40 "L'�v�nement indiqu� est incorrect: %s"

41 "Syntaxe: XmCommandAppendValue widget_command cha�ne"

42 "Syntaxe: XmCommandError widget_command message_erreur"

43 "Syntaxe: XmCommandSetValue widget_command commande"

44 "Syntaxe: XmCommandGetChild variable widget_command fils"

45 "Syntaxe: XmMessageBoxGetChild variable widget_command fils"

46 "Le widget doit �tre de type 'messageBox'."

47 "Syntaxe: XmFileSelectionBoxGetChild variable widget fils"

48 "Le widget doit �tre de type 'bo�te de s�lection de fichier'."

49 "Syntaxe: XmSelectionBoxGetChild variable widget fils"

50 "Le widget doit �tre de type 'bo�te de s�lection'."

51 "Syntaxe: XmScaleGetValue wdget_scale variable"

52 "Syntaxe: XmScaleSetValue widget_scale valeur"

53 "La valeur d'�chelle indiqu�e est incorrecte: %s."

54 "Syntaxe: XmScrollBarGetValues barre_d�fil variable variable variable variable"

55 "Syntaxe: XmScrollBarSetValues barre_d�fil valeur taille_r�gle incr�ment incr�ment_page notification"

56 "La valeur indiqu�e est incorrecte: %s."

57 "La taille indiqu�e pour la r�gle est incorrecte: %s."

58 "L'incr�ment indiqu� est incorrect: %s."

59 "L'incr�ment de page indiqu� est incorrect: %s."

60 "Syntaxe: XmScrollVisible fen�tre_d�fil widget marge_gauche_droite marge_sup_inf"

61 "Le widget doit �tre de type 'scrolledWindow'."

62 "Le widget � rendre visible n'existe pas."

63 "La valeur de marge gauche/droite indiqu�e est incorrecte: %s."

64 "La valeur de marge inf�rieure/sup�rieure indiqu�e est incorrecte: %s."

65 "Syntaxe: %s widget �tat notification"

66 "Syntaxe: ouverture_cat variable nom_cat"

67 "Syntaxe: fermeture_cat ID_cat"

68 "Syntaxe: catgets variable ID_cat Num_set Num_msg Msg_dft"

69 "Le widget doit �tre de type 'text' ou 'textField'."

70 "Syntaxe: %s variable widget"

71 "Syntaxe: %s widget bool�en"

72 "Le param�tre indiqu� est incorrect: %s."

73 "Syntaxe: %s widget lignes"

74 "Syntaxe: %s widget long_maxi"

75 "Syntaxe: %s widget cha�ne"

76 "Syntaxe: %s widget variable variable"

77 "Syntaxe: %s widget position cha�ne"

78 "Syntaxe: %s widget position variable variable"

79 "Syntaxe: %s widget position_source position_cible cha�ne"

80 "La position source indiqu�e est incorrecte: %s."

81 "La position cible indiqu�e est incorrecte: %s."

82 "Syntaxe: %s widget premi�re_position derni�re_position heure"

83 "La premi�re position indiqu�e est incorrecte: %s."

84 "La derni�re position indiqu�e est incorrecte: %s."

85 "L'heure indiqu�e est incorrecte: %s."

86 "Syntaxe: %s variable widget x y"

87 "La position x indiqu�e est incorrecte: %s."

88 "La position y indiqu�e est incorrecte: %s."

89 "Syntaxe: %s widget droite gauche mode"

90 "La position de gauche indiqu�e est incorrecte: %s."

91 "La position de droite indiqu�e est incorrecte: %s."

92 "Syntaxe: %s widget d�part cha�ne sens variable"

93 "La position de d�part indiqu�e est incorrecte: %s."

94 "Syntaxe: XmListGetSelectedPos variable widget"

95 "Syntaxe: XmListGetMatchPos variable widget �l�ment"

96 "Syntaxe: XmOptionLabelGadget variable widget"

97 "Syntaxe: XmOptionButtonGadget variable widget"

98 "Syntaxe: XmGetVisibility variable widget"

99 "Syntaxe: XmGetTearOffControl variable widget"

100 "Syntaxe: XmGetTabGroup variable widget"

101 "Syntaxe: XmGetPostedFromWidget variable widget"

102 "Syntaxe: XmGetFocusWidget variable widget"

103 "Syntaxe: XmFileSelectionDoSearch widget masque_r�pertoire"

$set 16        Redefine set#


1 "DtkshCvtNamedValueToString: Aucune correspondance trouv�e."

2 "DtkshCvtStringToNamedValue: Impossible de convertir la cha�ne '%s'."
$ The following messages are for ksh93 itself.  The message numbers must
$ match those specified in the MsgStr array allmsgs in
$ ksh93/src/cmd/ksh93/sh/init.c, as must the set number.

$set 25        Redefine set#


1 "Effectu�(es)"

3 "En cours d'ex�cution"

4 "[-n] [arg...]"

5 "[arg...]"

6 "[r�p] [liste]"

7 "[travail...]"

8 "[n]"

9 "[nom [chemin_acc�s] ]"

10 "[nom]"

11 "[sup] [base]"

12 "expr..."

13 "format [arg...]"

14 "est une fonction."

15 "est un mot cl�."

16 "est interne au shell."

17 "est une fonction export�e."

18 "est une fonction ind�finie."

19 "nom [arg...]"

20 "cha�ne_opt nom [args...]"

21 "secondes"

23 "${HOME:-.}/.profile"

24 "%c: L'expression contient un caract�re incorrect: %s ."

25 "%c: Le format d'identificateur est inconnu."

26 "%d-%d: Plage incorrecte."

27 "%d: Version de script binaire incorrecte."

28 "%s est un alias pour "

29 "%s est un alias export� pour "

30 "%s est manquant."

31 "%s: base inconnue."

32 "%s: ':' attendu pour l'op�rateur '?'."

33 "%s: Ambigu."

34 "%s: Les arguments doivent �tre des ID de processus ou des num�ros de %travaux."

35 "%s: alias introuvable.\n"

36 "%s: Erreur de syntaxe arithm�tique."

37 "%s: L'affectation n�cessite une lvalue."

38 "%s: Num�ro d'unit� de fichier incorrect."

39 "%s: Format incorrect."

40 "%s: Num�ro incorrect."

41 "%s: Option(s) incorrecte(s)."

42 "%s: Remplacement incorrect."

43 "%s: trap incorrect."

44 "%s: Cr�ation impossible."

45 "%s: Ex�cution impossible."

46 "%s: Ouverture impossible."

47 "%s: Division par z�ro."

48 "%s: Exception de domaine."

49 "%s: Echec de %s."

50 "%s: Le fichier existe d�j�."

51 "%s: Nom de fonction incorrect."

52 "%s: Nom d'alias incorrect."

53 "%s: Fonction de discipline incorrecte."

54 "%s: Nom d'exportation incorrect."

55 "%s: Nom de fonction incorrect."

56 "%s: Nom incorrect."

57 "%s: Expression r�guli�re incorrecte."

58 "%s: Auto-r�f�rence incorrecte."

59 "%s: Utilisation incorrecte de :"

60 "%s: Nom de variable incorrect."

61 "%s n'est pas un identificateur."

62 "%s est accessible en lecture seulement."

63 "%s: Libell� non mis en oeuvre."

64 "%s: Limite d�pass�e."

65 "%s: Des symboles plus nombreux �taient attendus."

66 "%s: Pas de p�re."

67 "%s: Pas de nom de r�f�rence."

68 "%s: Introuvable."

69 "%s: Non mis(e) en oeuvre."

70 "%s: Les op�randes sont de types incompatibles."

71 "%s: Exception de d�passement de capacit�."

72 "%s: Param�tre non d�fini."

73 "%s: Param�tre nul ou non d�fini."

74 "%s: Recursion trop profonde."

75 "%s: Une variable de r�f�rence ne peut pas �tre un tableau."

76 "%s requiert un chemin d'acc�s."

77 "%s: Restreint."

78 "%s: Exception de singularit�."

79 "%s: Indice hors limites."

80 "%s: Parenth�se manquante."

81 "%s: Fonction inconnue."

82 "%s: Environnement local inconnu."

83 "%s: Op�rateur inconnu."

84 "%s: Nom de signal inconnu."

85 "%s: Entra�nerait une boucle."

86 "(coredump)"

87 "-c requiert un argument."

88 "-e - requiert un argument unique."

89 "/vpix"

90 "<commande inconnue>"

91 "ACE#?F#?H:[nom]L#?R#?Z#?fi#?[base]lnprtux [nom=[valeur]...]"

92 "AE#?F#?HL#?R#?Z#?fi#?[base]lnprtux [nom=[valeur]...]"

93 "Abandon"

94 "Ad:[delim]prst#[d�lai]u#[num_fich] [nom...]"

95 "Appel d'un signal d'alarme"

96 "Sp�cification de noeud root incorrecte."

97 "Appel syst�me incorrect."

98 "Tube interrompu"

99 "Erreur de bus"

100 "Impossible de lancer la gestion des travaux."

101 "Param�tres en cours de l'option"

102 "Signal DIL"

103 "Fils arr�t�"

104 "DircabefhkmnpstuvxCI:[fichier]o:?[option]A:[nom] [arg...]"

105 "DircabefhkmnpstuvxCo:?[option]A:[nom] [arg...]"

106 "Interruption EMT"

107 "Limite de temps CPU d�pass�e."

108 "Limite de taille de fichier d�pass�e."

109 "Exception de calcul en virgule flottante"

110 "HSacdfmnstv [limite]"

111 "D�connexion"

112 "Signal d'E-S"

113 "Instruction interdite"

114 "Interruption"

115 "Arr�t�"

116 "LP [r�p] [modif]"

117 "Erreur de m�moire"

118 "Processus de migration"

119 "Pas de gestion des travaux"

120 "Interruption t�l�phone"

121 "Alarme d'appel s�lectif "

122 "Coupure d'alimentation"

123 "D�finition du profil de l'alarme"

124 "Quitter"

125 "Perte de ressources"

126 "Retour au pilote de tty pr�c�dent..."

127 "S [masque]"

128 "SIGAPOLLO"

129 "Libell� de s�curit� modifi�"

130 "Interruption de prise"

131 "Test sonore termin�"

132 "Fin (signal)"

133 "Fin (entr�e de tty)"

134 "Suite du processus interrompu"

135 "Arr�t�"

136 "Fin (sortie de tty)"

137 "Passage au nouveau pilote de tty..."

138 "Arr�t imminent du syst�me"

139 "Interrompu"

140 "Trace/Interruption BPT"

141 "Version inconnue"

142 "Entrez 'exit' pour mettre fin � ce shell."

143 "Signal utilisateur 1"

144 "Signal utilisateur 2"

145 "Version non d�finie"

146 "Signal de l'horloge virtuelle"

147 "Modification de taille de la fen�tre"

148 "Des travaux sont en cours d'ex�cution."

149 "Vous avez arr�t� des travaux."

150 "[_[:alpha:]]*([_[:alnum:]])"

151 "\n\
@(#)Version 12/28/93\0\n"

152 "\n\
@(#)Version M-12/28/93\0\n"

153 "\n\
r�el"

154 "\r\n\
\007D�passement de d�laid'inactivit� du shell dans 60 secondes."

155 "un nom..."

156 "a:c [commande [args...] ]"

157 "nom afpv..."

158 "alarm %s %.3f\n"

159 "alarm -r %s +%.3g\n"

160 "Argument attendu"

161 "R�pertoire incorrect"

162 "Num�ro d'unit� de fichier incorrect."

163 "Remplacement incorrect"

164 "Impossible d'acc�der aux r�pertoires p�res."

165 "Impossible de cr�er un tube."

166 "Impossible de cr�er un fichier temporaire."

167 "Impossible d'ex�cuter fork."

168 "Impossible d'obtenir %s."

169 "Impossible de d�finir %s."

170 "Impossible de d�finir l'alarme."

171 "Condition(s) requise(s)"

172 "dsf:[biblio] [nom...]"

173 "e:[editeur]lnrsN# [premier] [dernier]"

174 "Fin de fichier."

175 "f:[format]nprsu:[num_fich] [arg...]"

176 "nom fnv..."

177 "hist -e \"${VISUAL:-${EDITOR:-vi}}\" "

178 "Impossible d'ouvrir le fichier d'historique."

179 "Syntaxe incorrecte."

180 "Argument de type %c incorrect."

181 "est une version interne au shell de"

182 "est un alias rep�r� pour "

183 "kill"

184 "Ligne %d: $ non pr�c�d� de \\"

185 "Ligne %d: %c entre ${} doit �tre encadr� de guillemets."

186 "Ligne %d: %s Libell� inconnu."

187 "Ligne %d: %s entre [[...]] obsol�te ; utilisez ((...))."

188 "Ligne %d: '=' obsol�te ; utilisez '=='."

189 "Ligne %d: -a obsol�te ; utilisez -e."

190 "Ligne %d: \\ devant %c r�serv� pour une utilisation ult�rieure."

191 "Ligne %d: `...` obsol�te ; utilisez $(...)."

192 "Ligne %d: indiquez un caract�re d'�chappement pour %c afin d'�viter toute ambigu�t�."

193 "Ligne %d: libell� %s ignor�."

194 "Ligne %d: indiquez %c entre guillemets pour �viter toute ambigu�t�."

195 "Ligne %d: ensemble %s obsol�te."

196 "Ligne %d: Des espaces sont requis pour le sous-shell imbriqu�."

197 "Ligne %d: indiquez des accolades pour �viter toute ambigu�t� avec $id[...]."

198 "Ligne %d: indiquez un espace ou une tabulation pour s�parer les op�rateurs %c et %c."

199 "ln#[num_signal]s:[nom_signal] signal..."

200 "Shells de connexion setuid/setgid interdits."

201 "mappage"

202 "retour � la ligne"

203 "nlp [travail...]"

204 "Pas de fichier d'historique."

205 "Pas de processus d'interrogation."

206 "Ce travail n'existe pas."

207 "Ce processus n'existe pas."

208 "Non pris en charge."

209 "hors fonction"

210 "en fonction"

211 "Nombre maximal de fichiers ouverts d�pass�e."

212 "M�moire satur�e."

213 "p [action condition...]"

214 "p [nom[=valeur]...]"

215 "Param�tre non d�fini."

216 "Autorisation refus�e."

217 "Ce processus existe d�j�."

218 "ptx [nom=[valeur]...]"

219 "pvV nom [arg]..."

220 "r [nom_variable secondes]"

221 "Erreur de syntaxe � la ligne %d: `%s' %s"

222 "Erreur de syntaxe � la ligne %d: libell� en double %s."

223 "Erreur de syntaxe: `%s' %s"

224 "sys"

225 "D�passement de d�lai lors de l'attente d'entr�e."

226 "inattendu"

227 "universel inaccessible"

228 "illimit�"

229 "sans correspondance"

230 "utilisateur"

231 "versions"

232 "Echec de l'�criture dans %d."

233 "Vous avez du courrier dans $_"

234 "z�ro octet"
