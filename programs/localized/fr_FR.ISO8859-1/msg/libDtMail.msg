$ +SNOTICE
$ 
$ 	$TOG: libDtMail.msg /main/18 1999/03/26 16:46:50 mgreess $
$ 
$ 	RESTRICTED CONFIDENTIAL INFORMATION:
$ 	
$ 	The information in this document is subject to special
$ 	restrictions in a confidential disclosure agreement bertween
$ 	HP, IBM, Sun, USL, SCO and Univel.  Do not distribute this
$ 	document outside HP, IBM, Sun, USL, SCO, or Univel wihtout
$ 	Sun's specific written approval.  This documment and all copies
$ 	and derivative works thereof must be returned or destroyed at
$ 	Sun's request.
$ 
$ 	Copyright 1993, 1994, 1995 Sun Microsystems, Inc.  All rights reserved.
$ 
$ +ENOTICE
$ @(#)libDtMail.msg	1.9 23 May 1995

$quote "

$set 1 libDtMail API set
$ // DTME_NoError
1 "Aucune erreur n'a eu lieu."

$ // DTME_AlreadyLocked
2 "Le dossier est verrouill� par une autre session."

$ // DTME_BadArg
3 "Un argument incorrect a remplac� un param�tre de l'op�ration."

$ // DTME_BadMailAddress
4 "Impossible de traiter l'adresse de courrier sp�cifi�e."

$ // DTME_BadRunGroup
5 "Le programme dtmail n'est pas ex�cut� en tant que groupe \"mail\"."

$ // DTME_FileCreateFailed
6 "Cr�ation du fichier demand� impossible."

$ // DTME_FolderNotSet
7 "La bo�te aux lettres � incorporer n'est pas d�finie."

$ // DTME_GetLockRefused
8 "Refus de l'utilisateur de retirer le verrou d'une bo�te aux lettres verrouill�e."

$ // DTME_ImplFailure
9 "Impossible � l'impl�mentation sp�cifi�e d'ex�cuter l'op�ration demand�e."

$ // DTME_InitializationFailed
10 "Impossible d'initialiser l'instance."

$ // DTME_InternalFailure
11 "Une panne interne s'est produite au cours de l'op�ration."

$ // DTME_InvalidError
12 "La structure de l'erreur est incorrecte."

$ // DTME_InvalidOperationSequence
13 "Tentative d'op�ration avant l'initialisation de l'instance."

$ // DTME_MD5ChecksumFailed
14 "La signature MD5 n'est pas compatible avec le contenu du message."

$ // DTME_MailTransportFailed
15 "Communication impossible avec le transport du courrier."

$ // DTME_NoDataType
16 "Aucun type de donn�es compatible avec le type de transport."

$ // DTME_NoImplementations
17 "Impossible de trouver des impl�mentations dans la biblioth�que de courrier."

$ // DTME_NoMailBox
18 "Initialisation de la bo�te aux lettres au moment du chargement."

$ // DTME_NoMemory
19 "Pas de m�moire disponible pour l'op�ration."

$ // DTME_NoMsgCat
20 "Le catalogue de messages de DtMail n'existe pas."

$ // DTME_NoNewMail
21 "Pas de nouveau courrier � incorporer."

$ // DTME_NoObjectValue
22 "Valeur de l'objet introuvable."

$ // DTME_NoSuchFile
23 "La bo�te aux lettres n'existe pas et vous n'avez pas demand� sa cr�ation."

$ // DTME_NoSuchImplementation
24 "L'impl�mentation sp�cifi�e n'esiste pas."

$ // DTME_NoSuchType
25 "Le type de donn�es n'existe pas dans la biblioth�que."

$ // DTME_NoUser
26 "Impossible d'identifier l'utilisateur de la session."

$ // DTME_NotInbox
27 "Le fichier sp�cifi� n'est pas une bo�te aux lettres."

$ // DTME_NotLocked
28 "L'acc�s de la bo�te aux lettres n'est pas verrouill�."

$ // DTME_NotMailBox
29 "Le fichier demand� n'est pas une bo�te aux lettres d'un format connu dans cette impl�mentation."

$ // DTME_NotSupported
30 "L'impl�mentation en cours ne prend pas en charge cette op�ration."

$ // DTME_ObjectAccessFailed
31 "Impossible d'acc�der � un objet indispensable � l'op�ration."

$ // DTME_ObjectCreationFailed
32 " Impossible de cr�er un objet indispensable � l'op�ration."

$ // DTME_ObjectInUse
33 "Tentative d'initialisation d'un objet d�j� initialis�."

$ // DTME_ObjectInvalid
34 "Vous avez fait r�f�rence � un objet incorrect."

$ // DTME_OpenContainerInterrupted
35 "L'utilisateur a interrompu l'ouverture de la bo�te aux lettres."

$ // DTME_OperationInvalid
36 "Une erreur interne a eu lieu au cours de l'ex�cution de l'op�ration."

$ // DTME_OtherOwnsWrite
37 "Le droit en �criture de la bo�te aux lettres appartient � un autre programme de courrier."

$ // DTME_RequestDenied
38 "L'autre session a refus� la demande de verrou ou de copie."

$ // DTME_TTFailure
39 "Impossible de traiter un messageToolTalk."

$ // DTME_TransportFailed
40 "Le transport de distribution de courrier a �chou�."

$ // DTME_UnknownFormat
41 "Le message ne fait pas partie d'un format pris en charge."

$ // DTME_UnknownOpenError
42 "Une erreur inconnue a eu lieu lors de l'ouverture de la bo�te aux lettres."

$ // DTME_UserAbort
43 "L'utilisateur a abandonn� l'op�ration."

$ // DTME_UserInterrupted
44 "L'utilisateur a interrompu l'op�ration."

$ // DTME_ObjectReadOnly
45 "Les autorisations de la bo�te aux lettres sont en lecture seule."

$ // DTME_NoPermission
46 "L'utilisateur n'a pas d'autorisation d'acc�s � la bo�te aux lettres."

$ // DTME_IsDirectory
47 "Le chemin sp�cifi� est un r�pertoire."

$ // DTME_CannotRemoveStaleMailboxLockFile
48 "Impossible de verrouiller la bo�te aux lettres (impossible de supprimer le fichier ancien verrou).\nFichier Ancien verrou : %s\nRaison : %s"

$ // DTME_CannotCreateMailboxLockFile
49 "Impossible de verrouiller la bo�te aux lettres (impossible de cr�er un fichier verrou).\nMailbox lock file : %s\nRaison : %s"

$ // DTME_CannotCreateMailboxLockFile_NoPermission
50 "Impossible de cr�er un fichier verrou et de verrouiller la bo�te aux lettres parce que l'utilisateur \nne peut acc�der ni � la bo�te aux lettres ni au r�pertoire qui la contient "

$ // DTME_CannotCreateMailboxLockFile_IsDirectory
51 "Impossible de cr�er un fichier verrou et de verrouiller la bo�te aux lettres parce qu'il \nexiste d�j� un r�pertoire de m�me nom."

$ // DTME_CannotCreateMailboxLockFile_NoSuchFile
52 "Impossible de cr�er un fichier verrou et de verrouiller la bo�te aux lettres parce que l'un\ndes composants de son chemin n'est pas un r�pertoire."

$ // DTME_CannotCreateMailboxLockFile_RemoteAccessLost
53 " Impossible de cr�er un fichier verrou et de verrouiller la bo�te aux lettres parce que \nvous n'avez plus acc�s au syst�me �loign� sur lequel le fichier a �t� cr��."

$ // DTME_CannotObtainInformationOnOpenMailboxFile
54 "Impossible d'obtenir des informations au sujet du fichier bo�te aux lettres courant.\nFichier bo�te aux lettres : %s\nRaison : %s"

$ // DTME_CannotCreateTemporaryMailboxFile
55 "Impossible de cr�er un fichier bo�te aux lettres temporaire.\nFichier bo�te aux lettres temporaire : %s\nRaison : %s"

$ // DTME_CannotCreateTemporaryMailboxFile_NoPermission
56 " Impossible de cr�er un fichier bo�te aux lettres temporaire parce que l'utilisateur ne peut acc�der \nni � la bo�te aux lettres ni au r�pertoire qui la contient."

$ // DTME_CannotCreateTemporaryMailboxFile_IsDirectory
57 " Impossible de cr�er un fichier bo�te aux lettres temporaire parce qu'il existe d�j�\nun r�pertoire du m�me nom."

$ // DTME_CannotCreateTemporaryMailboxFile_NoSuchFile
58 " Impossible de cr�er un fichier bo�te aux lettres temporaire parce que l'un\ndes composants de son chemin n'est pas un r�pertoire."

$ // DTME_CannotCreateTemporaryMailboxFile_RemoteAccessLost
59 " Impossible de cr�er un fichier bo�te aux lettres temporaire parce que \nvous n'avez plus acc�s au syst�me �loign� sur lequel le fichier a �t� cr��."

$ // DTME_CannotSetPermissionsOfTemporaryMailboxFile
60 "Impossible de d�finir les autorisations du fichier bo�te aux lettres temporaire.\nFichier bo�te aux lettres temporaire : %s\nAutorisations demand�es : %o\nRaison : %s"

$ // DTME_CannotSetOwnerOfTemporaryMailboxFile
61 "Impossible d'�tablir l'utilisateur du fichier bo�te aux lettres.\nFichier bo�te aux lettres temporaire : %s\nUid du propri�taire demand�e : %d\nRaison: %s"

$ // DTME_CannotSetGroupOfTemporaryMailboxFile
62 "Impossible d'�tablir un groupe de fichiers bo�te aux lettres temporaire.\nFichier bo�te aux lettres temporaire : %s\nGid du groupe demand� : %d\nRaison: %s"

$ // DTME_CannotWriteToTemporaryMailboxFile
63 "Pas de permission en �criture dans le fichier bo�te aux lettres temporaire.\ nFichier bo�te aux lettres temporaire : %s\nRaison : %s"

$ // DTME_CannotWriteToTemporaryMailboxFile_ProcessLimitsExceeded
64 " Pas de permission en �criture dans le fichier bo�te aux lettres temporaire parce que\nla limite de taille ou la taille maximale a �t� atteinte."

$ // DTME_CannotWriteToTemporaryMailboxFile_RemoteAccessLost
65 " Pas de permission en �criture dans le fichier bo�te aux lettres temporaire parce que\nvous n'avez plus acc�s au syst�me �loign� sur lequel il a �t� cr��."

$ // DTME_CannotWriteToTemporaryMailboxFile_NoFreeSpaceLeft
66 " Pas de permission en �criture dans le fichier bo�te aux lettres temporaire parce qu'il n'y a plus\nd'espace disponible sur le p�riph�rique sur lequel il a �t� cr��."

$ // DTME_CannotReadNewMailboxFile
67 "Impossible de lire le nouveau fichier bo�te aux lettres\nRaison : %s"

$ // DTME_CannotReadNewMailboxFile_OutOfMemory
68 " Impossible de lire le nouveau fichier bo�te aux lettres parce que la m�moire est insuffisante pour l'op�ration"

$ // DTME_CannotRemoveMailboxLockFile
69 "Impossible de d�verrouiller (Impossible de supprimer le fichier verrou).\nFichier verrou bo�te aux lettres : %s\nRaison : %s"

$ // DTME_CannotRenameNewMailboxFileOverOld
70 "Impossible de renommer le nouveau fichier bo�te aux lettres comme l'ancien.\nCe dernier existe toujours mais le contenu complet et correct de la bo�te aux lettres a �t� sauvegard�\ndans le nouveau fichier.\nVous devez rectifier ceci manuellement aussit�t que possible.\nFichier bo�te aux lettres ancien : %s\nNouveau fichier bo�te aux lettres : %s\nRaison : %s"

$ // DTME_InternalAssertionFailure
71 "Une erreur interne s'est produite au cours de l'application.\nIl est impossible de continuer.\nCondition d'erreur : %s\n"

$ "-NEW"
$ // - DTME_ResourceParsingNoEndif
$
72 "An error occurred while parsing the .mailrc resource file.\nThere is a conditional if statement that does not have a corresponding endif statement.\n"
  
$ "-NEW"
$ // - DTME_AlreadyOpened
$
73 "This mail folder is already opened."

$ "-NEW"
$ // - DTME_OutOfSpace
$
74 "No Space on Temporary Filesystem."

$ "-NEW"
$ // - DTME_CannotCreateMailboxDotDtmailLockFile
75 "Mailer has detected a mailbox lockfile:\n%s"

$ "-NEW"
$ // - DTME_MailboxInodeChanged
76 "Mailer can no longer access this mailbox.\nIt would be best to close and reopen it."

$ "-NEW"
$ // - DTME_MailServerAccess_AuthorizationFailed
77 "Cannot retrieve mail for '%s@%s' using '%s'.\nAuthorization failed.  The server returned:\n     %s\n\nPlease enter a new password"
  
$ "-NEW"
$ // - DTME_MailServerAccess_Error
78 "Cannot retrieve mail for '%s@%s' using '%s'.\nThe server returned:\n     %s"

$ "-NEW"
$ // - DTME_MailServerAccess_MissingPassword
79 "Please enter a password for '%s@%s' using '%s'"

$ "-NEW"
$ // - DTME_MailServerAccess_ProtocolViolation
80 "Cannot retrieve mail for '%s@%s' using '%s'.\nClient/server protocol error."
  
$ "-NEW"
$ // - DTME_MailServerAccess_ServerTimeoutError
81 "Cannot retrieve mail for '%s@%s' using '%s'.\nTimed out waiting for server."
  
$ "-NEW"
$ // - DTME_MailServerAccess_SocketIOError
82 "Cannot retrieve mail for '%s@%s' using '%s'.\n%s."
  
$ "-NEW"
$ // - DTME_AppendMailboxFile_Error
83 "Cannot append to mailbox"
  
$ "-NEW"
$ // - DTME_AppendMailboxFile_FileTooBig
84 "Cannot append to mailbox:  %s\nSYSERROR(%d):  %s."
  
$ "-NEW"
$ // - DTME_AppendMailboxFile_LinkLost
85 "Cannot append to mailbox:  %s\nSYSERROR(%d):  %s."
  
$ "-NEW"
$ // - DTME_AppendMailboxFile_NoSpaceLeft
86 "Cannot append to mailbox:  %s\nSYSERROR(%d):  %s."
  
$ "-NEW"
$ // - DTME_AppendMailboxFile_SystemError
87 "Cannot append to mailbox:  %s\nSYSERROR(%d):  %s."

$ "-NEW"
$ // - DTME_GetmailCommandRetrieval_SystemError
88 "Getmail command failed:  %s\nSYSERROR(%d):  %s."

$ "-NEW"
$ // - DTME_GetmailCommandRetrieval_AbnormalExit
89 "Getmail command exited abnormally:  %s."
  
$ "-NEW"
$ // - DTME_PathElementPermissions
90 "Search permission denied on a component of the path prefix,\n'%s'."

$ "-NEW"
$ // - DTME_PathElementNotDirectory
91 "A component of the path prefix is not a directory,\n'%s'."

$ "-NEW"
$ // - DTME_PathElementDoesNotExist
92 "A component of the path prefix does not exist,\n'%s'."

$ "-NEW"
$ // - DTME_MailServerAccessInfo_SocketOpen
93 "Opening connection for '%s@%s'."
  
$ "-NEW"
$ // - DTME_MailServerAccessInfo_NoMessages
94 "No messages for '%s@%s'."
  
$ "-NEW"
$ // - DTME_MailServerAccessInfo_RetrievingMessage
95 "Retrieving message %d of %d for '%s@%s'."
 
$ "-NEW"
$ // - DTME_MailServerAccessInfo_MessageTooLarge
96 "Skipping oversized message (%d bytes)."
  

$
$ Strings from libDtMail/Common/DtMailValuesBuiltin.C

$set 2
$ /* NL_COMMENT
$  * The %C is the time and date format, please refer to strftime man page for 
$  * explanation of each format.
$  */
1 "%C" 
  

$
$ SockOpen error strings from libDtMail/Common/IO.C

$ "-NEW"
2 "Unknown host:  %s"

$ "-NEW"
3 "Error creating socket: %s"

$ "-NEW"
4 "Error connecting to socket:  %s"


$
$ FileShare error strings from libDtMail/Common/FileShare.C

$ "-NEW"
5 "Another user would like your lock."

$ "-NEW"
6 "Another session has this mailbox locked. Request access?"

$ "-NEW"
7 "Unable to obtain lock, open this mailbox as read only?"

$ "-NEW"
8 "Unable to obtain lock because system not responding, open this mailbox as read only, read write, or cancel?"

$ "-NEW"
9 "Another user has taken your lock."
