#include "feed.h"
#include "ui_feed.h"
#include"list.h"
#include<string>
#include<fstream>
#include"comment.h"

feed::feed(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::feed)
{
    users.open("users.txt");
    pages.open("pages.txt");
    posts.open("posts.txt");
    comments.open("comments.txt");
    liked=new char*[50];

    for(int i=0;i<50;i++)
    {
        liked[i]=new char[50];
    }
    ui->setupUi(this);
}


feed::~feed()
{
    delete ui;
}
void feed::getid(string d)
{
    id = d;
}
void feed::getdate(QString s)
{
    datestring=s;
    date = QDate::fromString(s, "MM-dd-yyyy");
    if (date.isValid()) {
        day = date.day();
        month = date.month();
        year = date.year();
    }


}
void feed::getname(string n )
{
    name=n;
}

void feed::print()
{

    if(ui->share)
        delete ui->share;

    string chkid;
    string chkpost;
    int pday;
    int pmonth;
    int pyear;
    int numofusers;
    string userid;
    string cmntsid;
    string cmntuser;
    ui->menu->setText("                   Showing All Posts   ");


    if(id=="u1")
    {
        likedpages=new char*[4];
        for(int i=0;i<4;i++)
        {
            likedpages[i] = new char[2];
        }
        likedpages[0]="p3";
        likedpages[1]="p4";
        likedpages[2]="p7";
        likedpages[3]="p8";

        friends=new char*[4];
        for(int i=0;i<4;i++)
        {
            friends[i] = new char[2];

        }

        friends[0]="u3";
        friends[1]="u4";
        friends[2]="u7";
        friends[3]="u9";

        numoffrnds=4;
        numofpages=4;
    }
    else if(id=="u2")
    {

        likedpages=new char*[7];
        for(int i=0;i<7;i++)
        {
            likedpages[i] = new char[2];
        }

        likedpages[0]="p1";
        likedpages[1]="p2";
        likedpages[2]="p3";
        likedpages[3]="p5";
        likedpages[4]="p7";
        likedpages[5]="p8";
        likedpages[6]="p9";

        friends=new char*[1];
        friends[0]=new char;

        numoffrnds=0;
        numofpages=7;
    }
    else if(id=="u3")
    {


        likedpages=new char*[5];
        for(int i=0;i<5;i++)
        {
            likedpages[i] = new char[2];
        }

        likedpages[0]="p2";
        likedpages[1]="p4";
        likedpages[2]="p5";
        likedpages[3]="p6";
        likedpages[4]="p8";

        friends=new char*[6];
        for(int i=0;i<6;i++)
        {
            friends[i] = new char[2];
        }

        friends[0]="u1";
        friends[1]="u4";
        friends[2]="u5";
        friends[3]="u6";
        friends[4]="u7";
        friends[5]="u8";

        numoffrnds=6;
        numofpages=5;
    }
    else if(id=="u4")
    {

        likedpages=new char*[3];
        for(int i=0;i<3;i++)
        {
            likedpages[i] = new char[2];
        }

        likedpages[0]="p1";
        likedpages[1]="p6";
        likedpages[2]="p8";

        friends=new char*[16];
        for(int i=0;i<16;i++)
        {
            friends[i] = new char[2];
        }

        friends[0]="u1";
        friends[1]="u3";
        friends[2]="u5";
        friends[3]="u6";
        friends[4]="u7";
        friends[5]="u8";
        friends[6]="u9";

        numoffrnds=16;
        numofpages=3;
    }


    //printing
    int dex=0;

    for(int j=0;j<pp;j++)
    {
        dex=0;
        posts>>chkid;
        posts>>chkpost;
        posts>>pday>>pmonth>>pyear;
        // qDebug()<<chkid<<chkpost<<pday<<pmonth<<pyear;

        char* temp = new char[80];
        do {
            posts.getline(temp, 80);
        } while (posts && temp[0] == '\0');

        string str;
        while (posts >> str && str != "-1")
        {
            liked[j][dex]=str[0];
            dex++;
            liked[j][dex]=str[1];
            dex++;
        }
        liked[j][dex+1]='-';
        //users
        if(chkid!=id)
        {
            //qDebug()<<friends[0][1]<<chkid[1];
            if(chkid[0]=='u')
            {
                for(int k=0;k<numoffrnds;k++)
                {
                    if(chkid==friends[k])
                    // if((pday==day||pday-1==day)&&pmonth==month&&pyear==year)
                    {
                        users>>numofusers;

                        for (int i = 0; i < numofusers; i++)
                        {
                            users>>userid;
                            char* tempp = new char[80];
                            do {
                                users.getline(tempp, 80);
                            } while (users && tempp[0] == '\0');
                            if(chkid==userid)
                            {
                                ui->list->addItem("------------------------------------------------------------------------------------------------------------------------");
                                QString show=QString::fromStdString(chkpost);
                                ui->list->addItem("<"+show+">"+(QString(tempp)) + " posted ("+QString::number(pmonth)+"/"+QString::number(pday)+"/"+QString::number(pyear)+"):-");

                            }
                        }
                        ui->list->addItem("                                    "+QString(temp));
                        ui->list->addItem(" ");
                        users.close();
                        users.open("users.txt");
                        //comments>>numofcmnts;
                        for(int h=0;h<numofcmnts;h++)
                        {
                            comments>>cmntsid;
                            comments>>cmntuser;
                            char* c = new char[80];
                            do {
                                comments.getline(c, 80);
                            } while (comments && c[0] == '\0');
                            if(cmntsid==chkpost)
                            {
                                //qDebug()<<cmntsid<<chkpost;
                                    users>>numofusers;

                                    for (int i = 0; i < numofusers; i++)
                                    {
                                        users>>userid;
                                        char* tempp = new char[80];
                                        do {
                                            users.getline(tempp, 80);
                                        } while (users && tempp[0] == '\0');

                                        if(cmntuser==userid)
                                        {
                                            ui->list->addItem(QString(tempp) + " Commented: "+(QString(c)));
                                        }

                                    }

                                    users.close();
                                    users.open("users.txt");
                                    // ui->list->addItem("------------------------------------------------------------------------------------------------------------------------");



                            }


                        }
                        comments.close();
                        comments.open("comments.txt");

                    }
                }
            }
            //pages
            if(chkid[0]=='p')
            {
                for(int k=0;k<numofpages;k++)
                {
                    //qDebug()<<chkid<<likedpages[k];
                    if(chkid==likedpages[k])
                    // if((pday==day||pday-1==day)&&pmonth==month&&pyear==year)
                    {
                        pages>>numofusers;

                        for (int i = 0; i < numofusers; i++)
                        {
                            pages>>userid;
                            char* tempp = new char[80];
                            do {
                                pages.getline(tempp, 80);
                            } while (pages && tempp[0] == '\0');
                            if(chkid==userid)
                            {
                                ui->list->addItem("------------------------------------------------------------------------------------------------------------------------");
                                QString show=QString::fromStdString(chkpost);
                                ui->list->addItem("<"+show+">"+(QString(tempp)) + " posted ("+QString::number(pmonth)+"/"+QString::number(pday)+"/"+QString::number(pyear)+"):-");

                            }
                        }
                        ui->list->addItem("                                    "+QString(temp));
                        ui->list->addItem(" ");
                        pages.close();
                        pages.open("pages.txt");

                       // comments>>numofcmnts;

                        for(int h=0;h<numofcmnts;h++)
                        {
                            comments>>cmntsid;
                            comments>>cmntuser;
                            char* c = new char[80];
                            do {
                                comments.getline(c, 80);
                            } while (comments && c[0] == '\0');
                            if(cmntsid==chkpost)
                            {
                                if(cmntuser[0]=='u')
                                {
                                    users>>numofusers;

                                    for (int i = 0; i < numofusers; i++)
                                    {
                                        users>>userid;
                                        char* tempp = new char[80];
                                        do {
                                            users.getline(tempp, 80);
                                        } while (users && tempp[0] == '\0');
                                        if(cmntuser==userid)
                                        {
                                            //qDebug()<<c;
                                            ui->list->addItem(QString(tempp) + " Commented: "+(QString(c)));
                                        }

                                    }

                                    users.close();
                                    users.open("users.txt");
                                    // ui->list->addItem("------------------------------------------------------------------------------------------------------------------------");
                                }
                                else
                                {
                                    if(cmntuser[0]=='p')
                                    {
                                        pages>>numofusers;

                                        for (int i = 0; i < numofusers; i++)
                                        {
                                            pages>>userid;
                                            char* tempp = new char[80];
                                            do {
                                                pages.getline(tempp, 80);
                                            } while (users && tempp[0] == '\0');
                                            if(cmntuser==userid)
                                            {
                                               // qDebug()<<c;
                                                ui->list->addItem(QString(tempp) + " Commented: "+(QString(c)));
                                            }

                                        }

                                        pages.close();
                                        pages.open("pages.txt");
                                        // ui->list->addItem("------------------------------------------------------------------------------------------------------------------------");
                                    }
                                }
                            }
                            }


                        }
                        comments.close();
                        comments.open("comments.txt");

                    }
                }
            }


        }
    oposts.open("shared.txt");
    for(int j=0;j<share;j++)
    {

        oposts>>chkid;
        oposts>>chkpost;
        oposts>>pday>>pmonth>>pyear;
        // qDebug()<<chkid<<chkpost<<pday<<pmonth<<pyear;

        char* temp = new char[80];
        do {
            oposts.getline(temp, 80);
        } while (oposts && temp[0] == '\0');

        //users
        if(chkid!=id)
        {
            for(int k=0;k<numoffrnds;k++)
            {
                if(chkid==friends[k])
                // if((pday==day||pday-1==day)&&pmonth==month&&pyear==year)
                {


                // if((pday==day||pday-1==day)&&pmonth==month&&pyear==year)

                    users>>numofusers;

                    for (int i = 0; i < numofusers; i++)
                    {
                        users>>userid;
                        char* tempp = new char[80];
                        do {
                            users.getline(tempp, 80);
                        } while (users && tempp[0] == '\0');
                        if(chkid==userid)
                        {
                            ui->list->addItem("------------------------------------------------------------------------------------------------------------------------");
                            QString show=QString::fromStdString(chkpost);
                            ui->list->addItem("<"+show+">"+(QString(tempp)) + " posted ("+QString::number(pmonth)+"/"+QString::number(pday)+"/"+QString::number(pyear)+"):-");

                        }
                    }
                    ui->list->addItem("                                    "+QString(temp));
                    ui->list->addItem(" ");
                    users.close();
                    users.open("users.txt");
                }
            }

        }
    }

    oposts.close();


    ui->list->addItem("------------------------------------------------------------------------------------------------------------------------");

}
void feed::home()
{
    if(ui->share)
        delete ui->share;
    string chkid;
    string chkpost;
    int pday;
    int pmonth;
    int pyear;
    int numofusers;
    string userid;
    string cmntsid;
    string cmntuser;

    ui->menu->setText("Showing Posts for the Date: "+datestring);

    if(id=="u1")
    {
        likedpages=new char*[4];
        for(int i=0;i<4;i++)
        {
            likedpages[i] = new char[2];
        }
        likedpages[0]="p3";
        likedpages[1]="p4";
        likedpages[2]="p7";
        likedpages[3]="p8";

        friends=new char*[4];
        for(int i=0;i<4;i++)
        {
            friends[i] = new char[2];

        }

        friends[0]="u3";
        friends[1]="u4";
        friends[2]="u7";
        friends[3]="u9";

        numoffrnds=4;
        numofpages=4;
    }
    else if(id=="u2")
    {

       likedpages=new char*[7];
        for(int i=0;i<7;i++)
        {
            likedpages[i] = new char[2];
        }

        likedpages[0]="p1";
        likedpages[1]="p2";
        likedpages[2]="p3";
        likedpages[3]="p5";
        likedpages[4]="p7";
        likedpages[5]="p8";
        likedpages[6]="p9";

        friends=new char*[1];
        friends[0]=new char;

        numoffrnds=0;
        numofpages=7;
    }
    else if(id=="u3")
    {


        likedpages=new char*[5];
        for(int i=0;i<5;i++)
        {
            likedpages[i] = new char[2];
        }

        likedpages[0]="p2";
        likedpages[1]="p4";
        likedpages[2]="p5";
        likedpages[3]="p6";
        likedpages[4]="p8";

        friends=new char*[6];
        for(int i=0;i<6;i++)
        {
            friends[i] = new char[2];
        }

        friends[0]="u1";
        friends[1]="u4";
        friends[2]="u5";
        friends[3]="u6";
        friends[4]="u7";
        friends[5]="u8";

        numoffrnds=6;
        numofpages=5;
    }
    else if(id=="u4")
    {

        likedpages=new char*[3];
        for(int i=0;i<3;i++)
        {
            likedpages[i] = new char[2];
        }

        likedpages[0]="p1";
        likedpages[1]="p6";
        likedpages[2]="p8";

        friends=new char*[16];
        for(int i=0;i<16;i++)
        {
            friends[i] = new char[2];
        }

        friends[0]="u1";
        friends[1]="u3";
        friends[2]="u5";
        friends[3]="u6";
        friends[4]="u7";
        friends[5]="u8";
        friends[6]="u9";

        numoffrnds=16;
        numofpages=3;
    }


    //printing

    int dex=0;
    for(int j=0;j<pp;j++)
    {
        dex=0;
        posts>>chkid;
        posts>>chkpost;
        posts>>pday>>pmonth>>pyear;
        // qDebug()<<chkid<<chkpost<<pday<<pmonth<<pyear;

        char* temp = new char[80];
        do {
            posts.getline(temp, 80);
        } while (posts && temp[0] == '\0');

        string str;
        while (posts >> str && str != "-1")
        {
            liked[j][dex]=str[0];
            dex++;
            liked[j][dex]=str[1];
            //qDebug()<<liked[j][dex-1]<<liked[j][dex];
            dex++;
        }

        //users
        if(chkid!=id)
        {
            //qDebug()<<friends[0][1]<<chkid[1];
            if(chkid[0]=='u')
            {
                for(int k=0;k<numoffrnds;k++)
                {
                    if(chkid==friends[k])
                     if((pday==day||pday==day-1)&&pmonth==month&&pyear==year)
                    {
                        users>>numofusers;

                        for (int i = 0; i < numofusers; i++)
                        {
                            users>>userid;
                            char* tempp = new char[80];
                            do {
                                users.getline(tempp, 80);
                            } while (users && tempp[0] == '\0');
                            if(chkid==userid)
                            {
                                ui->list->addItem("------------------------------------------------------------------------------------------------------------------------");
                                QString show=QString::fromStdString(chkpost);
                                ui->list->addItem("<"+show+">"+(QString(tempp)) + " posted ("+QString::number(pmonth)+"/"+QString::number(pday)+"/"+QString::number(pyear)+"):-");
                                //ui->list->addItem(" ");
                            }
                        }
                        ui->list->addItem("                                    "+QString(temp));
                        ui->list->addItem(" ");
                        users.close();
                        users.open("users.txt");
                       // comments>>numofcmnts;
                        for(int h=0;h<numofcmnts;h++)
                        {
                            comments>>cmntsid;
                            comments>>cmntuser;
                            char* c = new char[80];
                            do {
                                comments.getline(c, 80);
                            } while (comments && c[0] == '\0');
                            if(cmntsid==chkpost)
                            {
                               // qDebug()<<cmntsid<<chkpost;
                                users>>numofusers;

                                for (int i = 0; i < numofusers; i++)
                                {
                                    users>>userid;
                                    char* tempp = new char[80];
                                    do {
                                        users.getline(tempp, 80);
                                    } while (users && tempp[0] == '\0');

                                    if(cmntuser==userid)
                                    {
                                        ui->list->addItem(QString(tempp) + " Commented: "+(QString(c)));
                                    }

                                }

                                users.close();
                                users.open("users.txt");
                                // ui->list->addItem("------------------------------------------------------------------------------------------------------------------------");



                            }


                        }
                        comments.close();
                        comments.open("comments.txt");

                    }
                }
            }
            //pages
            if(chkid[0]=='p')
            {
                for(int k=0;k<numofpages;k++)
                {
                    //qDebug()<<chkid<<likedpages[k];
                    if(chkid==likedpages[k])
                     if((pday==day||pday==day-1)&&pmonth==month&&pyear==year)
                    {
                        pages>>numofusers;

                        for (int i = 0; i < numofusers; i++)
                        {
                            pages>>userid;
                            char* tempp = new char[80];
                            do {
                                pages.getline(tempp, 80);
                            } while (pages && tempp[0] == '\0');
                            if(chkid==userid)
                            {
                                ui->list->addItem("------------------------------------------------------------------------------------------------------------------------");
                                QString show=QString::fromStdString(chkpost);
                                ui->list->addItem("<"+show+">"+(QString(tempp)) + " posted ("+QString::number(pmonth)+"/"+QString::number(pday)+"/"+QString::number(pyear)+"):-");
                                //ui->list->addItem(" ");
                            }
                        }
                        ui->list->addItem("                                    "+QString(temp));
                        ui->list->addItem(" ");
                        pages.close();
                        pages.open("pages.txt");

                        //comments>>numofcmnts;

                        for(int h=0;h<numofcmnts;h++)
                        {
                            comments>>cmntsid;
                            comments>>cmntuser;
                            char* c = new char[80];
                            do {
                                comments.getline(c, 80);
                            } while (comments && c[0] == '\0');
                            if(cmntsid==chkpost)
                            {
                                if(cmntuser[0]=='u')
                                {
                                    users>>numofusers;

                                    for (int i = 0; i < numofusers; i++)
                                    {
                                        users>>userid;
                                        char* tempp = new char[80];
                                        do {
                                            users.getline(tempp, 80);
                                        } while (users && tempp[0] == '\0');
                                        if(cmntuser==userid)
                                        {
                                            //qDebug()<<c;
                                            ui->list->addItem(QString(tempp) + " Commented: "+(QString(c)));
                                        }

                                    }

                                    users.close();
                                    users.open("users.txt");
                                    // ui->list->addItem("------------------------------------------------------------------------------------------------------------------------");
                                }
                                else
                                {
                                    if(cmntuser[0]=='p')
                                    {
                                        pages>>numofusers;

                                        for (int i = 0; i < numofusers; i++)
                                        {
                                            pages>>userid;
                                            char* tempp = new char[80];
                                            do {
                                                pages.getline(tempp, 80);
                                            } while (users && tempp[0] == '\0');
                                            if(cmntuser==userid)
                                            {
                                                //qDebug()<<c;
                                                ui->list->addItem(QString(tempp) + " Commented: "+(QString(c)));
                                            }

                                        }

                                        pages.close();
                                        pages.open("pages.txt");
                                        // ui->list->addItem("------------------------------------------------------------------------------------------------------------------------");
                                    }
                                }
                            }
                        }


                    }
                    comments.close();
                    comments.open("comments.txt");

                }
            }
        }


    }
    oposts.open("shared.txt");
    for(int j=0;j<share;j++)
    {

        oposts>>chkid;
        oposts>>chkpost;
        oposts>>pday>>pmonth>>pyear;
        // qDebug()<<chkid<<chkpost<<pday<<pmonth<<pyear;

        char* temp = new char[80];
        do {
            oposts.getline(temp, 80);
        } while (oposts && temp[0] == '\0');

        //users
        if(chkid!=id)
        {
            for(int k=0;k<numoffrnds;k++)
            {
                if(chkid==friends[k])
                // if((pday==day||pday-1==day)&&pmonth==month&&pyear==year)
                {
            {

                // if((pday==day||pday-1==day)&&pmonth==month&&pyear==year)
                {
                    users>>numofusers;

                    for (int i = 0; i < numofusers; i++)
                    {
                        users>>userid;
                        char* tempp = new char[80];
                        do {
                            users.getline(tempp, 80);
                        } while (users && tempp[0] == '\0');
                        if(chkid==userid)
                        {
                            ui->list->addItem("------------------------------------------------------------------------------------------------------------------------");
                            QString show=QString::fromStdString(chkpost);
                            ui->list->addItem("<"+show+">"+(QString(tempp)) + " posted ("+QString::number(pmonth)+"/"+QString::number(pday)+"/"+QString::number(pyear)+"):-");

                        }
                    }
                    ui->list->addItem("                                    "+QString(temp));
                    ui->list->addItem(" ");
                    users.close();
                    users.open("users.txt");
                }
            }
                }
            }

        }
    }
    oposts.close();


    ui->list->addItem("------------------------------------------------------------------------------------------------------------------------");

}
void feed::timeline()
{

    if(ui->cmnt)
        delete ui->cmnt;
    if(ui->liked)
        delete ui->liked;
    if(ui->like)
        delete ui->like;
    if(ui->toolButton)
        delete ui->toolButton;
    string chkid;
    string chkpost;
    int pday;
    int pmonth;
    int pyear;
    int numofusers;
    string userid;
    string cmntsid;
    string cmntuser;

    QString idstring=QString::fromStdString(id);
    ui->menu->setText("      Showing Posts of User: "+idstring);


    //printing


    for(int j=0;j<pp;j++)
    {

        posts>>chkid;
        posts>>chkpost;
        posts>>pday>>pmonth>>pyear;
        // qDebug()<<chkid<<chkpost<<pday<<pmonth<<pyear;

        char* temp = new char[80];
        do {
            posts.getline(temp, 80);
        } while (posts && temp[0] == '\0');

        char* frnds=new char[80];
        do {
            posts.getline(frnds, 80);
        } while (posts && frnds[0] == '-');

        //users
        if(chkid==id)
        {
            //qDebug()<<friends[0][1]<<chkid[1];


                {

                ///if ((pyear < year) ||(pyear == year && pmonth < month) ||(pyear == year && pmonth == month && pday < day))
                    {
                        users>>numofusers;

                        for (int i = 0; i < numofusers; i++)
                        {
                            users>>userid;
                            char* tempp = new char[80];
                            do {
                                users.getline(tempp, 80);
                            } while (users && tempp[0] == '\0');
                            if(chkid==userid)
                            {
                                ui->list->addItem("------------------------------------------------------------------------------------------------------------------------");
                                QString show=QString::fromStdString(chkpost);
                                ui->list->addItem("<"+show+">"+(QString(tempp)) + " posted ("+QString::number(pmonth)+"/"+QString::number(pday)+"/"+QString::number(pyear)+"):-");

                            }
                        }
                        ui->list->addItem("                                    "+QString(temp));
                        ui->list->addItem(" ");
                        users.close();
                        users.open("users.txt");
                       // comments>>numofcmnts;
                        for(int h=0;h<numofcmnts;h++)
                        {
                            comments>>cmntsid;
                            comments>>cmntuser;
                            char* c = new char[80];
                            do {
                                comments.getline(c, 80);
                            } while (comments && c[0] == '\0');
                            if(cmntsid==chkpost)
                            {
                                //qDebug()<<cmntsid<<chkpost;
                                users>>numofusers;

                                for (int i = 0; i < numofusers; i++)
                                {
                                    users>>userid;
                                    char* tempp = new char[80];
                                    do {
                                        users.getline(tempp, 80);
                                    } while (users && tempp[0] == '\0');

                                    if(cmntuser==userid)
                                    {
                                        ui->list->addItem(QString(tempp) + " Commented: "+(QString(c)));
                                    }

                                }

                                users.close();
                                users.open("users.txt");
                                // ui->list->addItem("------------------------------------------------------------------------------------------------------------------------");



                            }


                        }
                        comments.close();
                        comments.open("comments.txt");

                    }
                }


        }


    }

    // memories

    oposts.open("shared.txt");
    for(int j=0;j<share;j++)
    {

        oposts>>chkid;
        oposts>>chkpost;
        oposts>>pday>>pmonth>>pyear;
        // qDebug()<<chkid<<chkpost<<pday<<pmonth<<pyear;

        char* temp = new char[80];
        do {
            oposts.getline(temp, 80);
        } while (oposts && temp[0] == '\0');

        //users
        if(chkid==id)
        {

                {

                    // if((pday==day||pday-1==day)&&pmonth==month&&pyear==year)
                    {
                        users>>numofusers;

                        for (int i = 0; i < numofusers; i++)
                        {
                            users>>userid;
                            char* tempp = new char[80];
                            do {
                                users.getline(tempp, 80);
                            } while (users && tempp[0] == '\0');
                            if(chkid==userid)
                            {
                                ui->list->addItem("------------------------------------------------------------------------------------------------------------------------");
                                QString show=QString::fromStdString(chkpost);
                                ui->list->addItem("<"+show+">"+(QString(tempp)) + " posted ("+QString::number(pmonth)+"/"+QString::number(pday)+"/"+QString::number(pyear)+"):-");

                            }
                        }
                        ui->list->addItem("                                    "+QString(temp));
                        ui->list->addItem(" ");
                        users.close();
                        users.open("users.txt");
                    }
                }

        }
    }
    oposts.close();
    ui->list->addItem("------------------------------------------------------------------------------------------------------------------------");

}



void feed::on_liked_clicked()
{
    string userid;
    List* l=new List;
    int dex=1;
    bool flag=1;



    for(int j=1;j<50;j++)
    {
        int numofusers;
        users>>numofusers;
        for (int i = 0; i < numofusers; i++)
        {
            users>>userid;
            char* temp = new char[80];
            do {
                users.getline(temp, 80);
            } while (users && temp[0] == '\0');


               if(userid[1]==liked[num-1][dex])
                {
                  l->add(temp);
                   dex=dex+2;
                  flag=0;
                }
               else if(liked[num-1][dex]=='u'||liked[num-1][dex]=='-')
                   dex++;
        }
        users.close();
        users.open(("Users.txt"));
    }
    if(flag)
        l->add("No Like");
    l->del();
    l->setWindowTitle("Liked By");
    l->show();

}


void feed::on_spinBox_valueChanged(int arg1)
{
    num=arg1;
}


void feed::on_like_clicked()
{
    int index=0;
    while(liked[num-1][index]!='-')
    {
        index++;
    }
    index++;
    liked[num-1][index]=id[0];
    liked[num-1][index+1]=id[1];
    qDebug()<<index;
    qDebug()<<liked[num-1][index];
    qDebug()<<liked[num-1][index+1];


}


void feed::on_share_clicked()
{
    string chkid;
    string chkpost;
    int pday;
    int pmonth;
    int pyear;
    char* temp;
    char* frnds;


        posts.close();
    posts.open("posts.txt");

    for(int i=0;i<num;i++)
    {

        posts>>chkid;
        posts>>chkpost;
        qDebug()<<chkid;
        posts>>pday>>pmonth>>pyear;
        // qDebug()<<chkid<<chkpost<<pday<<pmonth<<pyear;

        temp = new char[80];
        do {
            posts.getline(temp, 80);
        } while (posts && temp[0] == '\0');

        frnds=new char[80];
        do {
            posts.getline(frnds, 80);
        } while (posts && frnds[0] == '-');
    }



    qDebug()<<id<<chkid;
    qDebug()<<temp;
    if(id!=chkid)
        ui->list->addItem("choose your own post to share");
    else
    {

        posts.close();
        oposts.open("shared.txt", std::ios::in | std::ios::out | std::ios::ate);

        oposts<<chkid<<endl;
        oposts<<chkpost<<endl;
        oposts<<day<<" "<<month<<" "<<year<<endl;
        oposts<<name<<" shared a memory: "<<temp<<endl;
        share++;
        ui->list->addItem("shared successfully");
        oposts.close();
    }
}


void feed::on_cmnt_clicked()
{
    c1=new Comment;
    c1->show();

}


void feed::on_toolButton_clicked()
{
    string s=c1->getcmnt();
    comments.close();
    comments.open("comments.txt", std::ios::in | std::ios::out | std::ios::ate);
    comments<<"post"<<num<<" "<<id<<endl;
    comments<<s<<endl;
    numofcmnts++;
    comments.close();
}

