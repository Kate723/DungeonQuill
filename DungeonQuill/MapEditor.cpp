#include "MapEditor.h"
#include "qdebug.h"

QColor barrierColor = QColor(138, 105, 19);
QColor flatColor = QColor(249, 241, 219);
QColor piecesColor = QColor(130, 107, 72);

MapEditor::MapEditor(CombatMap* _map) :
	map(_map)
{
	ui.setupUi(this);

	connect(ui.mapTable, SIGNAL(currentItemChanged(QTableWidgetItem*, QTableWidgetItem*)), 
		this, SLOT(selectedItemChanged(QTableWidgetItem*, QTableWidgetItem*)));
	connect(ui.blockButton, SIGNAL(clicked()), this, SLOT(setBarrier()));
	connect(ui.characterButton, SIGNAL(clicked()), this, SLOT(setCharacter()));
	connect(ui.saveButton, SIGNAL(clicked()), this, SLOT(onSaveButtonClicked()));

	if (!map) {
		map = new CombatMap();
	}

	showMap();
}

MapEditor::~MapEditor()
{
}

void MapEditor::showMap() {
	for (int i = 0; i < MAX_SIZE; i++) {
		for (int j = 0; j < MAX_SIZE; j++) {
			QTableWidgetItem* gridItem = NULL;
			switch (map->grid[i][j])
			{
			case CombatMap::GridTag::Barrier:
				gridItem = tableItem(barrierColor,QString());
				ui.mapTable->setItem(i, j, gridItem);
				break;
			case CombatMap::GridTag::Flat:
				gridItem = tableItem(flatColor, QString());
				ui.mapTable->setItem(i, j, gridItem);
				break;
			default:
				break;
			}				
		}
	}

	for (auto i = map->piecesList.begin(); i != map->piecesList.end(); i++) {
		auto piece = (CombatPiece*)*i;
		QTableWidgetItem *gridItem = NULL;
		switch (piece->type)
		{
		case 1:
			gridItem = tableItem(piecesColor, piece->character->getName());
			ui.mapTable->setItem(piece->x, piece->y, gridItem); 
			break;
		case 2:
			gridItem = tableItem(piecesColor, piece->pieceInfo.getName());
			ui.mapTable->setItem(piece->x, piece->y, gridItem);
			break;
		default:
			break;
		}
	}

	ui.mapTable->verticalHeader()->setMinimumWidth(40);							//行表头宽度

	ui.mapTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	ui.mapTable->horizontalHeader()->setDefaultAlignment(Qt::AlignHCenter | Qt::AlignVCenter);		//表头内容居中

	ui.mapTable->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	ui.mapTable->verticalHeader()->setDefaultAlignment(Qt::AlignHCenter | Qt::AlignVCenter);		//表头内容居中

	ui.mapTable->setStyleSheet("QTableWidget::item:selected { background-color: rgb(166, 27, 41) }");
}

QTableWidgetItem* MapEditor::tableItem(QColor gridColor, QString& str) {
	auto item = new QTableWidgetItem(str);
	item->setFlags(item->flags() & ~Qt::ItemIsEditable);
	item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	item->setBackgroundColor(gridColor);

	return item;
}

void MapEditor::selectedItemChanged(QTableWidgetItem* current, QTableWidgetItem* previous) {
	QString selectGrid = "(" + QString::number(current->row() + 1) + ", " + QString::number(current->column() + 1) + ")";
	ui.selectGridText->setText(selectGrid);
	ui.selectGridText->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
}

void MapEditor::setBarrier() {
	auto selectedList = ui.mapTable->selectedItems();
	if (selectedList.isEmpty()) return;
	
	for (auto itor = selectedList.begin();itor != selectedList.end();itor++)
	{
		auto selected = *itor;
		auto gridItem = tableItem(barrierColor, QString());
		ui.mapTable->setItem(selected->row(), selected->column(), gridItem);
	}
}

void MapEditor::setCharacter() {
	auto selectedList = ui.mapTable->selectedItems();
	if (selectedList.isEmpty()) return;

	int characterNum = Adventurer::adventurerList.size() + Monster::monsterList.size();
	if (!characterNum) {
		QMessageBox::critical(NULL, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("无可选角色"), QMessageBox::Ok, QMessageBox::Ok);
		return;
	}

	auto characterChooseWin = new QWidget();
	characterChooseWin->setWindowModality(Qt::ApplicationModal);
	characterChooseWin->show();
	
	auto selected = selectedList.at(0);
	auto gridItem = tableItem(piecesColor, QString());
	ui.mapTable->setItem(selected->row(), selected->column(), gridItem);
}

void MapEditor::onSaveButtonClicked() {
	
	this->close();
}
