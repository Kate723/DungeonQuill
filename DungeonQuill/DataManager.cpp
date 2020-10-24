锘�#include "DataManager.h"
#include <QSqlError>
#include <QDebug>
//鍒涘缓鏁版嵁搴�
void DataManager::createDb()
{
    //法术数据库
    QSqlDatabase spelldb = QSqlDatabase::addDatabase("QSQLITE");
    spelldb.setDatabaseName("spell.db");
    if (!spelldb.open())
        exit(-1);
   
    //普通法术表
    QSqlQuery query;

    query.exec("create table spellBard (ID  int primary key)");
    
    query.prepare("insert into spellBard values (?)");
    List[0].clear();
    List[0] << 1001<<1000;
    query.addBindValue(List[0]);
    query.execBatch();

    spelldb.close();
   
    //装备数据库
    QSqlDatabase equdb = QSqlDatabase::addDatabase("QSQLITE");
    spelldb.setDatabaseName("equ.db");
    if (!equdb.open())
        exit(-1);

    //普通装备表
    query.exec("create table equipment (ID int ,name varchar(20),remark varchar(1000), type int)");

    query.prepare("insert into spellBard values (?,?,?,?)");
    for (int i = 0; i < 3; i++)
        List[i].clear();
    List[0] << 101 << 100;
    List[1] << "test2" << "test1";
    List[2] << "test2" << "test1";
    List[3] << 0 << 0;
    for (int i = 0; i < 3; i++)
        query.addBindValue(List[i]);
    query.execBatch();

    //武器表
    query.exec("create table weapon (ID int primary key,dN int ,dND  int ,dSN int ,tneedAmmunition  bool ,tisFinesse bool , type int,range int,"
       " tregularRange int  tmaxRange, int)");
    qs = "insert into Spell values (";
    for (int i = 0; i < 9; i++)
        qs = qs + "?";
    qs = qs + ")";
    query.prepare(qs);
    for (int i = 0; i < 9; i++)
        List[i].clear();
    List[0] << 101 << 100;
    List[1] << 3 << 2;
    List[2] << 3 << 2;
    List[3] << 3 << 2;
    List[4] << 1 << 0;
    List[5] << 1 << 0;
    List[6] << 3 << 2;
    List[7] << 3 << 2;
    List[8] << 3 << 2;
    for (int i = 0; i < 9; i++)
        query.addBindValue(List[i]);
    query.execBatch();

    //防御表
    query.exec("create table amour(ID int primary key,basicAC int,type int,strength  int) ");
    query.prepare("insert into amour values (?,?,?,?)");
    for (int i = 0; i < 3; i++)
        List[i].clear();
    List[0] << 101 << 100;
    List[1] << 3 << 2;
    List[2] << 3 << 2;
    List[3] << 3 << 2;
    for (int i = 0; i < 3; i++)
        query.addBindValue(List[i]);
    query.execBatch();

    equdb.close();

    //冒险者数据库
    QSqlDatabase advdb = QSqlDatabase::addDatabase("QSQLITE");
    spelldb.setDatabaseName("adv.db");
    if (!advdb.open())
        exit(-1);

    qs = "create table Adventurer(ttid int primary key, ttname varchar(20),tspeed  int,tmaxHitPoint  int,tcurHitPoint  int ,"
        "ttempHitPoint int,texp  int ,tsex  bool , tage int ,feet  int ,inch  int , tweight int , tideal varchar(20), tbond varchar(20), "
        "tflaw varchar(20),tapperance varchar(20), tbgStory varchar(20),ttttname varchar(20),ttttid  int,tsubName varchar(20),tsubID  int ,"
        "tid int , tname varchar(20), tremarks varchar(20),tttid  int ,tttname varchar(20), ttremarks varchar(20),tlevel  int ,"
        "tspecialAbilityName varchar(20),tcurSpecialPoint  int , tmaxSpecialPoint int,tcurHitDice int ,tmaxHitDice  int ,ticonPath varchar(20),"
        "cp int , sp int,ep  int ,gp  int ,pp  int, ";
    for (int i = 0; i < 3*vnum; i++)
    {
        qs = qs + "int";
    }
    qs = qs + ")";
    query.exec(qs);

    /*query.exec("select * from spellBard");
    while (query.next())
    {
            qDebug() << query.value(0);
    }*/
    
    
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
//鏌ヨ
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
