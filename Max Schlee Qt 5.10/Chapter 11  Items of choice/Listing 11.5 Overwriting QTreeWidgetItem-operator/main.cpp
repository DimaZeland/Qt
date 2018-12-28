bool MyТreeWidgetItem::operator(const QTreeWidgetItem& ptwiOther)
{
bool bRet = false;
int nColumn = treeWidget()->sortColumn();
if (nColumn == 0) {
QString strFormat = "dd.ММ.уууу";
bRet = QDate::fromString(text(nColumn)) < QDate::fromString(ptwi.text(nColumn) );
}
return bRet;
}
