
$ "$XConsortium: dtlp.msg /main/6 1996/10/16 03:16:39 cde-hit $";

$ *************************************<+>*************************************
$ *****************************************************************************
$ **
$ **  File:        dtlp.msg
$ **
$ **  Project:     DT printer utility (dtlp)
$ **
$ **  Description:
$ **  -----------
$ **  This file is the source for the message catalog for dtlp
$ **
$ **
$ *****************************************************************************
$ **
$ ** (c) Copyright 1990, 1992, 1993, 1994 Hewlett-Packard Company
$ ** (c) Copyright 1994 International Business Machines Corp.
$ ** (c) Copyright 1994 Sun Microsystems, Inc.
$ ** (c) Copyright 1994 Novell, Inc.
$ **
$ **     All Rights reserved
$ **
$ *****************************************************************************
$ *************************************<+>*************************************

$ *************************************<L>*************************************
$ **  -----------------GENERAL LOCALIZATION NOTES SECTION---------------------
$ * Comment lines begin with a $ except $set which indicates the start of a 
$ * new set.
$ *
$ * Do not delete any comments; you may add comments for your use.
$ *
$ * You don't need to localize the following sets:
$ *
$ * Please localize the following sets:
$ *  sets 1
$ **  ----------------GENERAL LOCALIZATION NOTES SECTION END------------------
$ *************************************<L>*************************************

$quote "

$set 1
$
$  -- The first group of messages all appear on the Print dialog --
$


$  This is the message that appears in the "Printer Name:" field when no
$  printer name has been specified and no there is no default printer.
10 "�ǥե����"

$  This is the label that appears in the title bar of the print dialog.
20 "����"

$  This is the label for the field indicating the file that will be printed.
30 "�ե�����:"

$  This is the label for the field indicating the name of the printer.
40 "�ץ��:"

$  This is the message that will appear in the "Printer:" field if no printer
$  has been specified.
50 "�ǥե����"

$  This is the label for the field indicating the number of copies to print.
60 "��������:"

$  This is the label for the field indicating the title for the banner page.
70 "�Хʡ��ڡ����Υ����ȥ�:"

$  This is the label for the field indicating if page numbers are to be added.
80 "�ڡ����ֹ����"

$  This is thef label for the field indicating additional options for the
$  "lp" command.
90 "�������ޥ�ɥ��ץ����:"

$  This is the label on the left button. Pushing this button causes the
$  dialog to disappear and the print operation to start.
100 "����"

$  This is the label on the center button. Pushing this button causes the
$  dialog to disappear and cancels the print operation.
110 "��ä�"

$  This is the label on the right button. Pushing this button causes a
$  help dialog to be posted.
120 "�إ��"

$
$  -- The following are error messages. --
$

$  This message is posted when there is a problem with the file specified. 
$  The file name will be appended to the message. One additional message
$  from the list below will also be included in the dialog to provide
$  more details.
130 "�����Ǥ��ޤ���:"

$  This message is added to the error dialog when the file is not printable 
$  or does not exist.
132 "����Υե�����ϰ�����ǽ�ʥե�����ǤϤʤ�����¸�ߤ��ޤ���"

$  This message is added to the error dialog when the file is not readable 
$  by the user invoking dtlp.
134 "�桼���ϡ����Υե�������ɤ߼�긢����äƤ��ޤ���"

$  This message is added to the error dialog when there is a general failure 
$  in setting up to print.
136 "�ե����뤬¸�ߤ��뤫�ɤ�����ǧ���Ƥ���������"

$  This is the label that appears in the title bar of the error dialog.
160 "��������"

$
$  -- Strings used in the Print dialog and Select Printer dialog in CDEnext --
$
$  This is the label for the field indicating the file(s) that will be printed.
170 "�ե�����̾: "

$  This is used as the window title of the Select Printer dialog and a button
$  in that dialog.
180 "�ץ������"

$  This is the label for the printer list in the Select Printer dialog.
190 "ͭ���ʥץ��:"

$  This is the label for the text box in the Select Printer dialog.
200 "�ץ�󥿾���:"

$
$  -- The following are error messages added for CDEnext --
$
$  File is not printable or does not exist.
210 "���Υե�����ϰ�����ǽ�ʥե�����ǤϤʤ�����¸�ߤ��ޤ���"

$  File is not printable or does not exist.
220 "�����ƥ��ǥץ�����������Ƥ��ʤ������ץ�󥿤�������ǽ���֤ˤ���ޤ���"

$  Printer does not exist.
230 "�ץ�󥿤�¸�ߤ��ޤ���"

$  Printer is not enabled.
240 "�ץ�󥿤ϰ�����ǽ���֤ˤ���ޤ���"

$  No default printer.
250 "�ǥե���ȥץ�󥿤ǤϤ���ޤ���"

$  Printer not accepting requests.
260 "�ץ�󥿤ϥꥯ�����Ȥ�����դ��ޤ���"

$  Number of copies is not a positive integer.
270 "���������������Ǥʤ���Фʤ�ޤ���"


$set 99
$    DO NOT TRANSLATE THESE MESSAGES
$    DO NOT CHANGE THESE MESSAGES
$    DO NOT LOCALIZE THESE MESSAGES
$    These messages are used for the version information.
$quote
1 @(#)version_goes_here
2 \n@(#)_DtMessage catalog source $XConsortium: dtlp.msg /main/6 1996/10/16 03:16:39 cde-hit $