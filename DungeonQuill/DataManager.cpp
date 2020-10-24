#include "DataManager.h"
#include <QSqlError>
#include <QDebug>
//创建数据库
void DataManager::createDb()
{
    QSqlDatabase spelldb = QSqlDatabase::addDatabase("QSQLITE");
    spelldb.setDatabaseName("spell.db");
    if (!spelldb.open())
        exit(-1);
   
    QSqlQuery query;

    //法术总表
    query.exec("create table DamageSpell(ID  int primary key, nameCh varchar(20), nameEn varchar(20), schoolID int, level int, isRitual bool,"
        "CastingTimelength int, CastingTimeremarks varchar(20), range int, isSelfOnly bool, SpellComponmentsverbalNeed bool,"
        "SpellComponmentssomaticNeed bool, SpellComponmentsmaterialNeed bool, SpellComponmentsremark varchar(20), DurationconcentrationNeed bool,"
        "Durationtime int, Durationremarks varchar(20), targetNeed bool, targetNum int, AreashapeID int, Areasize int, remarks varchar(20), "
        "attackRollNeed bool, savingThrowNeed bool, savingThrowTypeID int, damageType int, DiceRollTypediceNum int, DiceRollTypediceNumDependence int,"
        "DiceRollTypediceSideNum int, DamageSpellNum int)");
   
    //吟游诗人
    query.exec("create table spellBard (ID  int primary key)");
    
    query.prepare("insert into spellBard values (?)");
    QVariantList IDList;
    IDList << 1002<<1001;
    query.addBindValue(IDList);
    query.execBatch();
    

    query.exec("select * from spellBard");
    while (query.next())
    {
            qDebug() << query.value(0);
    }
    
    
    /*for (int i = 0; query.next(); i++)
    {
        for (int j = 1; j < 5; j++)
            qDebug()<< query.value(j);
            //ui.spellTable->setItem(i, j, new QTableWidgetItem(query.value(j).toString()));
    }*/
}
std::vector<DamageSpell*> DamageSpell::DamageSpellList;
void DataManager::download()
{
    QSqlQuery query;
    query.exec("select * from DamageSpell");
    while (query.next())
    {
        DamageSpell *ds = new DamageSpell(query.value(0).toInt(), query.value(1).toString().toStdString(), query.value(2).toString().toStdString(),
            query.value(4).toInt(),query.value(5).toInt(), query.value(6).toBool(), query.value(7).toInt(), query.value(8).toString().toStdString(), 
            query.value(9).toInt(),query.value(10).toBool(), query.value(11).toBool(), query.value(12).toBool(), query.value(13).toBool(), 
            query.value(14).toString().toStdString(), query.value(15).toBool(), query.value(16).toInt(), query.value(17).toString().toStdString(), 
            query.value(18).toBool(), query.value(19).toInt(),query.value(20).toInt(), query.value(21).toInt(), query.value(22).toString().toStdString(), 
            query.value(23).toBool(), query.value(24).toBool(),query.value(25).toInt(), query.value(26).toInt(), query.value(27).toInt(), 
            query.value(28).toInt(), query.value(29).toInt());
        DamageSpell::DamageSpellList.push_back(ds);
    }
}


/*
//查询
void DungeonQuill::queryClick()
{
    int qlevel = ui.comboBox_level->currentIndex();
    int qjob = ui.comboBox_job->currentIndex();
    QString q = "select * from";
    if (qjob == 0)
        q = q + "sysobjects";
    else
        q = q + "spell_" + QString::number(qjob);
    if (qlevel == 0)
        q = q;
    else
        q = q + "where level==" + QString::number(qlevel);
    QSqlQuery query;
    query.prepare(q);
    for(int i = 0;query.next();i++)
    {
        for (int j = 1; j < 5; j++)
            ui.spellTable->setItem(i, j, new QTableWidgetItem(query.value(j).toString()));
    }
}

*/
