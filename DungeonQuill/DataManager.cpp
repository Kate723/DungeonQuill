#include "DataManager.h"
#include <QSqlError>
#include <QDebug>
//创建数据库
void DataManager::createDb()
{
    //法术数据库
    QSqlDatabase spelldb = QSqlDatabase::addDatabase("QSQLITE","spellConnection");
    spelldb.setDatabaseName("spell.db");
    if (!spelldb.open())
        exit(-1);
   
    //普通法术表
    QSqlQuery query(spelldb);
    query.exec("create table Spell(ID  int primary key, nameCh varchar(20), nameEn varchar(20), schoolID int, level int, isRitual bool,"
        "CastingTimelength int, CastingTimeremarks varchar(1000), range int, isSelfOnly bool, SpellComponmentsverbalNeed bool,"
        "SpellComponmentssomaticNeed bool, SpellComponmentsmaterialNeed bool, SpellComponmentsremark varchar(1000), DurationconcentrationNeed bool,"
        "Durationtime int, Durationremarks varchar(1000), targetNeed bool, targetNum int, AreashapeID int, Areasize int, remarks varchar(1000))");
    
    QString qs = "insert into Spell values (";
    for (int i = 0; i < 21; i++)
        qs = qs + "?,";
    qs = qs + "?)";
    query.prepare(qs);
    QVariantList List[30];
    List[0] <<1001 << 1000;
    List[1] << "测试二" << "测试一";
    List[2] << "test2" << "test1";
    List[3] << 3 << 2;
    List[4] << 3<< 2;
    List[5] << 1 << 0;
    List[6] << 3 << 2;
    List[7] << "test2" << "test1";
    List[8] << 3 << 2;
    List[9] << 1 << 0;
    List[10] << 1 << 0;
    List[11] << 1 << 0;
    List[12] << 1 << 0;
    List[13] << "test2" << "test1";
    List[14] << 1 << 0;
    List[15] << 3 << 2;
    List[16] << "test2" << "test1";
    List[17] << 1 << 0;
    List[18] << 3 << 2;
    List[19] << 3 << 2;
    List[20] << 3 << 2;
    List[21] << "test2" << "test1";
    for (int i = 0; i < 22; i++)
        query.addBindValue(List[i]);
    query.execBatch();
   
    //伤害法术表
    query.exec("create table damageSpell(ID  int primary key, attackRollNeed int, savingThrowNeed int, savingThrowTypeID int, damageType int," 
        "DiceRollTypediceNum int, DiceRollTypediceNumDependence int,DiceRollTypediceSideNum int)");
    qs = "insert into damageSpell values (";
    for (int i = 0; i < 7; i++)
        qs = qs + "?,";
    qs = qs + "?)";
    query.prepare(qs);
    for (int i = 0; i < 8; i++)
        List[i].clear();
    List[0]<< 1001 << 1000;
    List[1] << 1 << 0;
    List[2] << 1 << 0;
    List[3] << 3 << 2;
    List[4] << 3 << 2;
    List[5] << 3 << 2;
    List[6] << 3 << 2;
    List[7] << 3 << 2;
    for (int i = 0; i < 8; i++)
        query.addBindValue(List[i]);
    query.execBatch();
    
    //治愈法术表
    query.exec("create table healSpell(ID  int primary key, DiceRollTypediceNum int, DiceRollTypediceNumDependence int,"
        "DiceRollTypediceSideNum int)");
    query.prepare("insert into healSpell values(?,?,?,?)");
    for (int i = 0; i < 4; i++)
        List[i].clear();
    List[0] << 1001 << 1000;
    List[1] << 3 << 2;
    List[2] << 3 << 2;
    List[3] << 3 << 2;
    for (int i = 0; i < 4; i++)
        query.addBindValue(List[i]);
    query.execBatch();

    spelldb.close();

    /*//吟游诗人法术表
    query.exec("create table spellBard (ID  int primary key)");
    
    query.prepare("insert into spellBard values (?)");
    List[0].clear();
    List[0] << 1001<<1000;
    query.addBindValue(List[0]);
    query.execBatch();

  
   
    //装备数据库
    QSqlDatabase equdb = QSqlDatabase::addDatabase("QSQLITE","equConnection");
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
    QSqlDatabase advdb = QSqlDatabase::addDatabase("QSQLITE","advConnection");
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
    query.exec(qs);*/

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
std::vector<HealSpell*>HealSpell::HealSpellList;
std::vector<Spell*> Spell::SpellList;
int Spell::spellNum;
int DamageSpell::damageSpellNum;
int HealSpell::healSpellNum;
void DataManager::download()
{
    //法术
    QSqlDatabase spelldb = QSqlDatabase::database("spellConnection");
    if (!spelldb.open())
        exit(-1);
   
    //伤害
    QSqlQuery query1(spelldb);
    QSqlQuery query2(spelldb);
    query1.exec("select * from damageSpell");
    while (query1.next())
    {
        DamageSpell::damageSpellNum++;
        query2.exec("select * from Spell where ID ="+query1.value(0).toString());
        query2.next();
        DamageSpell *ds = new DamageSpell(query2.value(0).toInt(), query2.value(1).toString().toStdString(), query2.value(2).toString().toStdString(),
            query2.value(3).toInt(),query2.value(4).toInt(), query2.value(5).toBool(), query2.value(6).toInt(), query2.value(7).toString().toStdString(), 
            query2.value(8).toInt(),query2.value(9).toBool(), query2.value(10).toBool(), query2.value(11).toBool(), query2.value(12).toBool(), 
            query2.value(13).toString().toStdString(), query2.value(14).toBool(), query2.value(15).toInt(), query2.value(16).toString().toStdString(), 
            query2.value(17).toBool(), query2.value(18).toInt(),query2.value(19).toInt(), query2.value(20).toInt(), query2.value(21).toString().toStdString(), 
            query1.value(1).toInt(), query1.value(2).toInt(),query1.value(3).toInt(), query1.value(4).toInt(), query1.value(5).toInt(),
            query1.value(6).toInt(), query1.value(7).toInt());
        DamageSpell::DamageSpellList.push_back(ds);
    }

    //治疗
    query1.exec("select * from healSpell");
    while (query1.next())
    {
        HealSpell::healSpellNum++;
        query2.exec("select * from Spell where ID = " + query1.value(0).toString());
        query2.next();
        HealSpell* hs = new HealSpell(query2.value(0).toInt(), query2.value(1).toString().toStdString(), query2.value(2).toString().toStdString(),
            query2.value(3).toInt(), query2.value(4).toInt(), query2.value(5).toBool(), query2.value(6).toInt(), query2.value(7).toString().toStdString(),
            query2.value(8).toInt(), query2.value(9).toBool(), query2.value(10).toBool(), query2.value(11).toBool(), query2.value(12).toBool(),
            query2.value(13).toString().toStdString(), query2.value(14).toBool(), query2.value(15).toInt(), query2.value(16).toString().toStdString(),
            query2.value(17).toBool(), query2.value(18).toInt(), query2.value(19).toInt(), query2.value(20).toInt(), query2.value(21).toString().toStdString(),
            query1.value(1).toInt(), query1.value(2).toInt(), query1.value(3).toInt());
        HealSpell::HealSpellList.push_back(hs);
    }

    //普通
    query2.exec("select * from Spell where ID not in (selest ID from damageSpell) and ID not in (selest ID from healSpell)");
    while (query2.next())
    {
        Spell::spellNum++;
        Spell* s = new Spell(query2.value(0).toInt(), query2.value(1).toString().toStdString(), query2.value(2).toString().toStdString(),
            query2.value(3).toInt(), query2.value(4).toInt(), query2.value(5).toBool(), query2.value(6).toInt(), query2.value(7).toString().toStdString(),
            query2.value(8).toInt(), query2.value(9).toBool(), query2.value(10).toBool(), query2.value(11).toBool(), query2.value(12).toBool(),
            query2.value(13).toString().toStdString(), query2.value(14).toBool(), query2.value(15).toInt(), query2.value(16).toString().toStdString(),
            query2.value(17).toBool(), query2.value(18).toInt(), query2.value(19).toInt(), query2.value(20).toInt(), query2.value(21).toString().toStdString());
        Spell::SpellList.push_back(s);
    }
    
    spelldb.close();
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
