$ $XConsortium: dthelpgen.msg /main/4 1996/10/16 03:15:11 cde-hit $
$ *****************************************************************************
$
$ ***** NOTE FOR MESSAGE CATALOG TRANSLATORS *****
$
$ There may be three types of messages in this file:
$
$  1. Messages that appear in dialogs or are displayed to the user.
$
$     These messages are the default and they should ALL BE LOCALIZED.
$     Note that these messages do NOT have any identification (see the
$     comments for type 2 and 3 below).
$
$  2. Messages that only appear in the DT error log file ($HOME/.dt/errorlog).
$
$     The localization of these messages is OPTIONAL.  These messages are
$     identified by the following:
$
$  MESSAGES xx-yy IN SET zz WILL ONLY APPEAR IN THE DT ERRORLOG FILE
$
$  3. Messages that should not be localized.
$
$     These messages are identified by the following:
$
$  DO NOT TRANSLATE or CHANGE or LOCALIZE MESSAGES xx-yy from set zz
$
$ ***** END (NOTE FOR MESSAGE CATALOG TRANSLATORS) *****
$
$ ******************************************************************************
$
$set 1
$
$ _DtMessage 1 is the usage message
$
$ Localize only the words 'directory', 'name', and 'language'.
$ 'directory' means the directory name in which the resulting files
$ will be placed. 'name' mean what base name to give the files placed
$ in 'directory'. 'language' means which localized versions of help files
$ to look for.
$
1 %s -dir <�ǥ��쥯�ȥ�> [-generate] [-file <�ե�����̾>] [-lang <����>]\n

$
$ Mesages 2-18 are error messages.
$
2 %s: %s �����Ǥϥǥ��쥯�ȥ�ǤϤ���ޤ���\n
3 %s: �ǥ��쥯�ȥ� %s �ؤΥ������������ݤ���ޤ�����\n\
�����ѡ��桼���ǻ�Ԥ��ޤ���?\n
4 %s: %s �����Ǥ�¸�ߤ��ޤ���\n
5 %s: %s ������ե����롦�����ƥब���äѤ��Ǥ���\n
6 %s: %s �˥��������Ǥ��ޤ��󡣥��顼�����ơ������ֹ� %d\n
7 %s: %s ������ե����롦�����ƥ���ɤ߼�����ѤǤ���\n
8 %s: %s �˽񤭹���ˤϡ�root �Υ�����������ɬ�פǤ���\n
9 %s: %s �ؤν񤭹��ߤ�̵���Ǥ���\n
10 %s: �����ѥ������Ǥ���\n
11 %s: 'title' �꥽����������ޤ���\n
12 %s: 'abstract' �꥽����������ޤ���\n
13 %s: 'volumes' �꥽����������ޤ���\n
14 %s: 'character' ����꥽����������ޤ���\n
15 %s: ������ǥ��쥯�ȥ꤬����ޤ���\n
16 %s: �������ե��ߥꡦ�ե����뤬����ޤ���\n
17 %s: �������ܥ�塼�ࡦ�ե����뤬����ޤ���\n
18 %s: ���ߤκ�ȥǥ��쥯�ȥ�˥��������Ǥ��ޤ��󡣥��顼�����ơ������ֹ� %d\n
19 %s: ����������Ƥ��ޤ���\n
20 %s: ����� %s �����ƥ�����̵���Ǥ���\n

$
$set 2
$
$ Specifies the character set used to create this file
$
$ This must be localized for the various languages. That is
$ for Japanese shift JIS, it would be 'ja_JP.SJIS'; for Japanese 
$ EUC it would be 'ja_JP.eucJP'. For files written using
$ HP Roman8 character set it would be '<lang+terr>.HP-ROMAN8', etc.
$ The set of allowable locale strings can be found in
$ /usr/dt/config/svc/CDE.lcx
$
1 ja_JP.HI-SJIS

$
$ Specifies the title for the browser.
$ It is used in the body of text displayed to the user.
$
2 �إ�ס��ޥ͡�����λ���ˡ

$
$ Specifies the body of text displayed in the browser.
$
$ When localizing, DO NOT alter any text between the "<" and ">" pairs.
$ That is - DO NOT localize the tags such as <ABBREV> and <PARAGRAPH>.
$           DO     localize the text between the tags.
$
3 <ABBREV>�إ�ס��ޥ͡�����λ���ˡ</ABBREV>\
<PARAGRAPH>�ʲ��γƥ����ȥ�ϡ����󥹥ȡ��뤵�졢����饤�󡦥إ�פ�\n\
��Ͽ����Ƥ���<ANGLE italic>�ץ������ȡ��ե��ߥ�</>�򼨤��Ƥ��ޤ���\n\
�ƥ����ȥ�(����ӥ�������)�ϡ��ե��ߥ���Υإ�פ�ꥹ�Ȥ�ɽ������\n\
�ϥ��ѡ���󥯤Ǥ���</>\
<PARAGRAPH after 0 first 1 left 3 label "<CHAR C.DT-SYMBOL-1><0xB7></>">\
�ץ������ȡ��ե��ߥ�ǻ��Ѳ�ǽ�ʥإ�פΥꥹ�Ȥ�ɽ������ˤϡ������ȥ�\n\
(�����դ��Υƥ�����)�ޤ��ϥ�����������򤷤Ƥ���������</PARAGRAPH>\
<PARAGRAPH after 0 first 1 left 3 label "<CHAR C.DT-SYMBOL-1><0xB7></>">\
�ץ������ȡ��ե��ߥ���ǡ�ɽ���������إ�פ򸡺����ơ����Υ����ȥ��\n\
���򤷤Ƥ���������</PARAGRAPH>\
<PARAGRAPH first 1 left 3 label "<CHAR C.DT-SYMBOL-1><0xB7></>">\
�إ�ס�������ɥ��������˥إ�פ�ɬ�פʾ��ϡ�F1 �����򲡤��Ƥ���������</PARAGRAPH>

$
$ Specifies the Volume Title
$
4 �إ�� - �ȥåץ�٥�

$
$ Specifies the preamble to the help file if no volumes or family files
$ are found.
$
$ When localizing, DO NOT alter any text between the "<" and ">" pairs.
$ That is - DO NOT localize the tags such as <ABBREV> and <PARAGRAPH>.
$           DO     localize the text between the tags.
$
5 <ABBREV>�إ�ס��ޥ͡�����λ���ˡ</ABBREV>\
<LINK 0 "Help4Help How-To-Register-Help">\
<TYPE serif><WEIGHT bold><SIZE 12><ANGLE italic>\
����:\ \ \ �إ�פ���Ͽ����Ƥ��ޤ���\
</SIZE></WEIGHT></TYPE></></LINK>\
<PARAGRAPH leftindent 3 firstindent 3>\
<WEIGHT bold>�ץ������ȡ��ե��ߥ�ˤ���Ͽ�ѤߤΥ֥饦���ѥ���饤��\n\
�إ�פϤ���ޤ���</>�إ�פϡ����ץꥱ���������ǥإ�ס����ޥ�ɤ�\n\
ľ�����򤹤뤳�Ȥˤ�äơ����Υ��ץꥱ�������ǻ��Ѳ�ǽ�ˤʤ�ޤ���</>

$
$ Specifies the title to use in the dthelpgen dtksh dialog.
$
6 dthelpgen

$
$ Specifies the message to display in the dthelpgen dtksh dialog.
$ This message indicates that dthelpgen is building (or rebuilding)
$ the browser information.
$
7 �֥饦������������Ǥ������Ф餯���Ԥ�����������

$
$set 3
$
$ ******* Text Formatting Templates ********
$ DO NOT TRANSLATE THESE MESSAGES
$ DO NOT CHANGE THESE MESSAGES
$ DO NOT LOCALIZE THESE MESSAGES
$
1 <TOPIC charset %s>
2 <TITLE><TYPE serif><WEIGHT bold><SIZE 14>%s</SIZE></WEIGHT></TYPE></TITLE>
3 <PARAGRAPH before 1 first 1 left 1>
4 <CHARACTERSET %s>
5 <TYPE serif><WEIGHT bold><SIZE 12><ANGLE italic>%s</></></></>
6 <PARAGRAPH before 1 first 1 left 1 graphic %s glink %s gtypelink 0>
7 <PARAGRAPH before 1 first 1 left 1 graphic %s glink "%s %s" gtypelink 1>

