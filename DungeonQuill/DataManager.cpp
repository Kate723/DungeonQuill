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
    QSqlQuery squery(spelldb);
    squery.exec("create table Spell(ID  int primary key, nameCh varchar(20), nameEn varchar(20), schoolID int, level int, isRitual bool,"
        "CastingTimelength int, CastingTimeremarks varchar(1000), range int, isSelfOnly bool, SpellComponmentsverbalNeed bool,"
        "SpellComponmentssomaticNeed bool, SpellComponmentsmaterialNeed bool, SpellComponmentsremark varchar(1000), DurationconcentrationNeed bool,"
        "Durationtime int, Durationremarks varchar(1000), targetNeed bool, targetNum int, AreashapeID int, Areasize int, remarks varchar(1000))");
    
    QString qs;
    /*qs = "insert into Spell values (";
    for (int i = 0; i < 21; i++)
        qs = qs + "?,";
    qs = qs + "?)";
    squery.prepare(qs);
    QVariantList List[40];
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
        squery.addBindValue(List[i]);
    squery.execBatch();*/
   
    //伤害法术表
    squery.exec("create table damageSpell(ID  int primary key, attackRollNeed int, savingThrowNeed int, savingThrowTypeID int, damageType int," 
        "DiceRollTypediceNum int, DiceRollTypediceNumDependence int,DiceRollTypediceSideNum int)");
    /*qs = "insert into damageSpell values (";
    for (int i = 0; i < 7; i++)
        qs = qs + "?,";
    qs = qs + "?)";
    squery.prepare(qs);
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
        squery.addBindValue(List[i]);
    squery.execBatch();*/
    
    //治愈法术表
    squery.exec("create table healSpell(ID  int primary key, DiceRollTypediceNum int, DiceRollTypediceNumDependence int,"
        "DiceRollTypediceSideNum int)");
    /*squery.prepare("insert into healSpell values(?,?,?,?)");
    for (int i = 0; i < 4; i++)
        List[i].clear();
    List[0] << 1001 << 1000;
    List[1] << 3 << 2;
    List[2] << 3 << 2;
    List[3] << 3 << 2;
    for (int i = 0; i < 4; i++)
        squery.addBindValue(List[i]);
    squery.execBatch();*/

    spelldb.close();

    /*//吟游诗人法术表
    query.exec("create table spellBard (ID  int primary key)");
    
    query.prepare("insert into spellBard values (?)");
    List[0].clear();
    List[0] << 1001<<1000;
    query.addBindValue(List[0]);
    query.execBatch();*/

  
   
    //装备数据库
    QSqlDatabase equdb = QSqlDatabase::addDatabase("QSQLITE","equConnection");
    equdb.setDatabaseName("equ.db");
    if (!equdb.open())
        exit(-1);

    //普通装备表
    QSqlQuery equery(equdb);
    equery.exec("create table equipment (ID int primary key,name varchar(20),remark varchar(1000), type int)");
    /*equery.prepare("insert into equipment values (?,?,?,?)");
    for (int i = 0; i < 4; i++)
        List[i].clear();
    List[0] << 101 << 100;
    List[1] << "test2" << "test1";
    List[2] << "test2" << "test1";
    List[3] << 0 << 0;
    for (int i = 0; i < 4; i++)
        equery.addBindValue(List[i]);
    equery.execBatch();*/

    //武器表
    equery.exec("create table weapon (ID int primary key,dN int ,dND  int ,dSN int ,tneedAmmunition  bool ,tisFinesse bool , type int,range int,"
       " tregularRange int , tmaxRange int)");
    /*qs = "insert into weapon values (";
    for (int i = 0; i < 9; i++)
        qs = qs + "?,";
    qs = qs + "?)";
    equery.prepare(qs);
    for (int i = 0; i < 10; i++)
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
    List[9] << 3 << 2;
    for (int i = 0; i < 10; i++)
        equery.addBindValue(List[i]);
    equery.execBatch();*/

    //防御表
    equery.exec("create table amour(ID int primary key,basicAC int,type int,strength  int) ");
    /*equery.prepare("insert into amour values (?,?,?,?)");
    for (int i = 0; i < 4; i++)
        List[i].clear();
    List[0] << 101 << 100;
    List[1] << 3 << 2;
    List[2] << 3 << 2;
    List[3] << 3 << 2;
    for (int i = 0; i < 4; i++)
        equery.addBindValue(List[i]);
    equery.execBatch();*/

    equdb.close();

    //冒险者数据库
    QSqlDatabase advdb = QSqlDatabase::addDatabase("QSQLITE","advConnection");
    advdb.setDatabaseName("adv.db");
    if (!advdb.open())
        exit(-1);

    QSqlQuery aquery(advdb);
    qs = "create table Adventurer(ID int primary key, ttname varchar(20),tspeed  int,tmaxHitPoint  int,tcurHitPoint  int ,"
        "ttempHitPoint int,texp  int ,tsex  bool , tage int ,feet  int ,inch  int , tweight int ,talignment int,"
        "trait1 varchar(1000), trait2 varchar(1000),tideal varchar(1000), tbond varchar(1000), "
        "tflaw varchar(1000),tapperance varchar(1000), tbgStory varchar(1000),ttttname varchar(20),ttttid  int,tsubName varchar(20),tsubID  int ,"
        "tid int , tname varchar(20), tremarks varchar(1000),tttid  int ,tttname varchar(20), ttremarks varchar(1000),tlevel  int ,"
        "tspecialAbilityName varchar(20),tcurSpecialPoint int ,tmaxSpecialPoint int, m0 int, m1 int, m2 int,m3 int , m4 int,m5 int,"
        " m6 int, m7 int, m8 int, m9 int, c0 int, c1 int, c2 int, c3 int, c4 int, c5 int, c6 int,c7 int ,c8 int ,c9 int , "
        "tcurHitDice int ,tmaxHitDice  int ,ticonPath varchar(1000),"
        "cp int , sp int,ep  int ,gp  int ,pp  int";
    for (int i = 0; i < vnum; i++)
    {
        qs = qs + ",equipment"+QString::number(i,10)+" int";
    }
    for (int i = 0; i < vnum; i++)
    {
        qs = qs + ",weapon" + QString::number(i, 10) + " int";
    }
    for (int i = 0; i < vnum; i++)
    {
        qs = qs + ",amour" + QString::number(i, 10) + " int";
    }
    qs = qs + ")";
    aquery.exec(qs);
    /*qs = "insert into Adventurer (ID, ttname,tspeed, tmaxHitPoint, tcurHitPoint ,ttempHitPoint, texp, tsex, tage, feet, inch , tweight, tideal, tbond,"
        "tflaw ,tapperance , tbgStory,ttttname ,ttttid ,tsubName ,tsubID,tid , tname , tremarks ,tttid  ,tttname, ttremarks ,tlevel,"
        "tspecialAbilityName,tcurSpecialPoint , tmaxSpecialPoint,tcurHitDice,tmaxHitDice  ,ticonPath ,cp, sp ,ep,gp ,pp )values (";
    for (int i = 0; i < 38; i++)
        qs = qs + "?,";
    qs = qs + "?)";
    aquery.prepare(qs);
    for (int i = 0; i < 39; i++)
        List[i].clear();
    List[0] << 1001 << 1000;
    List[1] << "test1" <<"test2";
    List[2] << 3 << 2;
    List[3] << 3 << 2;
    List[4] << 3 << 2;
    List[5] << 3 << 2;
    List[6] << 3 << 2;
    List[7] << 1 << 0;
    List[8] << 3 << 2;
    List[9] << 3 << 2;
    List[10] << 3 << 2;
    List[11] << 3 << 2;
    List[12] << "test2" << "test1";
    List[13] << "test2" << "test1";
    List[14] << "test2" << "test1";
    List[15] << "test2" << "test1";
    List[16] << "test2" << "test1";
    List[17] << "test2" << "test1";
    List[18] << 3 << 2;
    List[19] << "test2" << "test1";
    List[20] << 3 << 2;
    List[21] << 3 << 2;
    List[22] << "test2" << "test1";
    List[23] << "test2" << "test1";
    List[24] << 3 << 2;
    List[25] << "test2" << "test1";
    List[26] << "test2" << "test1";
    List[27] << 3 << 2;
    List[28] << "test2" << "test1";
    List[29] << 3 << 2;
    List[30] << 3 << 2;
    List[31] << 3 << 2;
    List[32] << 3 << 2;
    List[33] << "test2" << "test1";
    List[34] << 3 << 2;
    List[35] << 3 << 2;
    List[36] << 3 << 2;
    List[37] << 3 << 2;
    List[38] << 3 << 2;
    for (int i = 0; i < 39; i++)
        aquery.addBindValue(List[i]);
    aquery.execBatch();*/

    advdb.close();
}

std::vector<DamageSpell*> DamageSpell::DamageSpellList;
std::vector<HealSpell*>HealSpell::HealSpellList;
std::vector<Spell*> Spell::spellList;
std::vector<Adventurer*>Adventurer:: adventurerList;
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
        Spell::spellList.push_back(s);
    }
    
    spelldb.close();

    //冒险者
    QSqlDatabase advdb = QSqlDatabase::database("advConnection");
    if (!advdb.open())
        exit(-1);
    QSqlQuery aquery(advdb);
    aquery.exec("select * from Adventurer");
    while (aquery.next())
    {
        Adventurer* a = new Adventurer(aquery.value(0).toInt(), aquery.value(1).toString().toStdString(), aquery.value(2).toInt(),
            aquery.value(3).toInt(), aquery.value(4).toInt(), aquery.value(5).toInt(), aquery.value(6).toInt(), aquery.value(7).toBool(),
            aquery.value(8).toInt(), aquery.value(9).toInt(), aquery.value(10).toInt(), aquery.value(11).toInt(), aquery.value(12).toString().toStdString(),
            aquery.value(13).toString().toStdString(), aquery.value(14).toString().toStdString(), aquery.value(15).toString().toStdString(), aquery.value(16).toString().toStdString(),
            aquery.value(17).toString().toStdString(), aquery.value(18).toInt(), aquery.value(19).toString().toStdString(), aquery.value(20).toInt(), aquery.value(21).toInt(),
            aquery.value(22).toString().toStdString(), aquery.value(23).toString().toStdString(), aquery.value(24).toInt(),
            aquery.value(25).toString().toStdString(), aquery.value(26).toString().toStdString(), aquery.value(27).toInt(), aquery.value(28).toString().toStdString(), aquery.value(29).toInt(),
            aquery.value(30).toInt(), aquery.value(31).toInt(), aquery.value(32).toInt(), aquery.value(33).toString(), aquery.value(34).toInt(),
            aquery.value(35).toInt(), aquery.value(36).toInt(), aquery.value(37).toInt(), aquery.value(38).toInt());
        Adventurer::adventurerList.push_back(a);
    }

    advdb.close();
}



