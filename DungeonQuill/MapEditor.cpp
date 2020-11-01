#include "MapEditor.h"

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
	connect(ui.saveButton, SIGNAL(clicked()), this, SLOT(onSaveButtonClicked()));

	if (!map) {
		map = new CombatMap();
	}
	setWindowTitle(map->mapInfo.getName());

	showMap();
	setText();
}

MapEditor::~MapEditor()
{
}

void MapEditor::showMap() 
{
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

	ui.mapTable->verticalHeader()->setMinimumWidth(40);							//行表头宽度

	ui.mapTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	ui.mapTable->horizontalHeader()->setDefaultAlignment(Qt::AlignHCenter | Qt::AlignVCenter);		//表头内容居中

	ui.mapTable->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	ui.mapTable->verticalHeader()->setDefaultAlignment(Qt::AlignHCenter | Qt::AlignVCenter);		//表头内容居中

	ui.mapTable->setStyleSheet("QTableWidget::item:selected { background-color: rgb(166, 27, 41) }");
}

void MapEditor::setText()
{
	ui.mapNameTextEdit->setPlainText(map->mapInfo.getName());
	ui.mapRemarksTextEdit->setPlainText(QString::fromUtf8(map->mapInfo.remarks.c_str()));
}

QTableWidgetItem* MapEditor::tableItem(QColor gridColor, QString& str) 
{
	auto item = new QTableWidgetItem(str);
	item->setFlags(item->flags() & ~Qt::ItemIsEditable);
	item->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	item->setBackgroundColor(gridColor);

	return item;
}

void MapEditor::selectedItemChanged(QTableWidgetItem* current, QTableWidgetItem* previous) 
{
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
		QTableWidgetItem* gridItem = NULL;
		switch (map->grid[selected->row()][selected->column()])
		{
		case CombatMap::GridTag::Barrier:
			map->grid[selected->row()][selected->column()] = CombatMap::GridTag::Flat;
			gridItem = tableItem(flatColor, QString());
			ui.mapTable->setItem(selected->row(), selected->column(), gridItem);
			break;
		case CombatMap::GridTag::Flat:
			map->grid[selected->row()][selected->column()] = CombatMap::GridTag::Barrier;
			gridItem = tableItem(barrierColor, QString());
			ui.mapTable->setItem(selected->row(), selected->column(), gridItem);
			break;
		default:
			break;
		}		
	}
}

void MapEditor::onSaveButtonClicked() {
	map->mapInfo.name = ui.mapNameTextEdit->toPlainText().toStdString();
	map->mapInfo.remarks = ui.mapRemarksTextEdit->toPlainText().toStdString();
	CombatMap::mapList.push_back(map);

	this->close();
	DungeonQuill::renewMapList();
}
