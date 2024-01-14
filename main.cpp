#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <chrono>
#include <fstream>
#include <ctime>


using namespace std;


class Step
{
public:
    virtual string execute() const = 0;
    virtual void run() = 0;
    virtual ~Step() {}
};


class TitleStep : public Step
{
private:
    string titlu;
    string subtitlu;

public:
    TitleStep(string title, string subtitle)
        : titlu(title), subtitlu(subtitle) {}

    string execute() const override
    {
        return "Executare TITLE step: " + titlu + " " + subtitlu;
    }

    void run() override
    {
        cout << "Executare TITLE step: " << titlu << " - " << subtitlu << endl;
    }
};


class TextStep : public Step
{
private:
    string titlu;
    string copie;

public:
    TextStep(string title, string copyy)
        : titlu(title), copie(copyy) {}

    string execute() const override
    {
        return "Executare TEXT step: " + titlu + " - " + copie;
    }

    void run() override
    {
        cout << "Executare TEXT step: " << titlu << " - " << copie << endl;
    }
};


class TextInputStep : public Step
{
private:
    string descriere;
    string text;

public:
    TextInputStep(string descriere)
        : descriere(descriere) {}

    string execute() const override
    {
        return  "Executare TEXT input step: " + descriere ;
    }

    void run() override
    {
        cout<<"Executare TEXT input step: " ;
        cout << descriere << endl;
        cout<<"Va rugam introduceti un text:";
        getline(cin, text);
    }
};


class NumberInputStep : public Step
{
private:
    int numar;
    string descriere;
    int eroare1=0;

public:
    NumberInputStep(string descriere_nr)
        : descriere(descriere_nr), numar(0) {}

    string execute() const override
    {
        cout << "Executare Number input step: " << descriere << endl;
        return "";
    }

    void run() override
    {
        cout << "Executare Number input step: " << descriere << "-->";
        cin >> numar;
        while (true)
        {
            try
            {
                if (numar > 0 && numar < 10000000)
                {

                    cout << "Ati introdus corect" << endl;
                    break;

                }
                else
                {
                    throw(numar);
                }
            }
            catch (int e)
            {
                eroare1++;
                cout << "Va rugam mai introduceti o data, de data asta un numar valid: ";
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cin >> numar;
            }
        }
    }

    int getNumar() const
    {
        return numar;
    }

    void setNumar(int value)
    {
        numar = value;
    }

    int getEroare1() const
    {
        return eroare1;

    }
};


class CalculStep : public Step
{
private:
    string operatie;
    NumberInputStep* numberInputStep;
    int eroare2=0;
public:
    CalculStep(string operatie, NumberInputStep* numInputStep)
        : operatie(operatie), numberInputStep(numInputStep) {}

    string execute() const override
    {
        return "Vom avea o operatie de : " + operatie ;

    }

    void run() override
    {
        cout<<"Executare Calculus step:"<<endl;
        if (numberInputStep == nullptr)
        {
            cout << "Eroare: Nu a fost setat un pas de tip Number Input pentru pasul de tip Calculus." << endl;
            return;
        }

        int nr_nou;
        cout << "Numarul curent: " << numberInputStep->getNumar() << endl;




        if (operatie == "adunare")
        {
            cout << "Cu ce numar doriti sa adunati?: ";
            cin >> nr_nou;
            while (true)
            {
                try
                {
                    if (nr_nou > 0 && nr_nou < 10000000)
                    {
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        cout << "Ati introdus corect" << endl;
                        break;
                    }
                    else
                    {
                        throw(nr_nou);
                    }
                }
                catch (int e)
                {
                    eroare2++;
                    cout << "Va rugam mai introduceti o data, de data asta un numar valid: ";
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cin >> nr_nou;
                }
            }
            cout << "Suma celor doua numere este: " << numberInputStep->getNumar() + nr_nou << endl;
            numberInputStep->setNumar(numberInputStep->getNumar() + nr_nou);
        }
        else if (operatie == "scadere")
        {
            cout << "Cu ce numar doriti sa scadeti?: ";
            cin >> nr_nou;
            while (true)
            {
                try
                {
                    if (nr_nou > 0 && nr_nou < 10000000)
                    {
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        cout << "Ati introdus corect" << endl;
                        break;
                    }
                    else
                    {
                        throw(nr_nou);
                    }
                }
                catch (int e)
                {
                    eroare2++;
                    cout << "Va rugam mai introduceti o data, de data asta un numar valid: ";
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cin >> nr_nou;
                }
            }
            cout << "Diferenta celor doua numere este: " << numberInputStep->getNumar() - nr_nou << endl;
            numberInputStep->setNumar(numberInputStep->getNumar() - nr_nou);
        }
        else if(operatie == "inmultire")
        {
            cout<<"Cu ce numar doriti sa inmultiti?: ";
            cin>>nr_nou;
            while (true)
            {
                try
                {
                    if (nr_nou > 0 && nr_nou < 10000000)
                    {
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        cout << "Ati introdus corect" << endl;
                        break;
                    }
                    else
                    {
                        throw(nr_nou);
                    }
                }
                catch (int e)
                {
                    eroare2++;
                    cout << "Va rugam mai introduceti o data, de data asta un numar valid: ";
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cin >> nr_nou;
                }
            }
            cout<<"Inmultirea celor doua numere este: "<<numberInputStep->getNumar() * nr_nou;
            cout<<endl;
            numberInputStep->setNumar(numberInputStep->getNumar() * nr_nou);

        }
        else if(operatie == "impartire")
        {
            cout<<"Cu ce numar doriti sa impartiti?: ";
            cin>>nr_nou;
            while (true)
            {
                try
                {
                    if (nr_nou > 0 && nr_nou < 10000000)
                    {
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        cout << "Ati introdus corect" << endl;
                        break;
                    }
                    else
                    {
                        throw(nr_nou);
                    }
                }
                catch (int e)
                {
                    eroare2++;
                    cout << "Va rugam mai introduceti o data, de data asta un numar valid: ";
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cin >> nr_nou;
                }
            }
            cout<<"Impartirea celor doua numere este: "<<numberInputStep->getNumar() / nr_nou;
            cout<<endl;
            numberInputStep->setNumar(numberInputStep->getNumar() / nr_nou);
        }
        else if(operatie == "minim")
        {
            cout<<"Cu ce numar doriti sa comparati?: ";
            cin>>nr_nou;
            while (true)
            {
                try
                {
                    if (nr_nou > 0 && nr_nou < 10000000)
                    {
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        cout << "Ati introdus corect" << endl;
                        break;
                    }
                    else
                    {
                        throw(nr_nou);
                    }
                }
                catch (int e)
                {
                    eroare2++;
                    cout << "Va rugam mai introduceti o data, de data asta un numar valid: ";
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cin >> nr_nou;
                }
            }
            cout<<"Cea mai mica valoare dintre cele doua numere este: ";
            if(numberInputStep->getNumar()>nr_nou)
            {
                cout<<nr_nou;
                cout<<endl;
                numberInputStep->setNumar(nr_nou);
            }
            else
            {
                cout<<numberInputStep->getNumar()<<endl;
                numberInputStep->setNumar(numberInputStep->getNumar());
            }


        }
        else if(operatie == "maxim")
        {
            cout<<"Cu ce numar doriti sa comparati?: ";
            cin>>nr_nou;
            while (true)
            {
                try
                {
                    if (nr_nou > 0 && nr_nou < 10000000)
                    {
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        cout << "Ati introdus corect" << endl;
                        break;
                    }
                    else
                    {
                        throw(nr_nou);
                    }
                }
                catch (int e)
                {
                    eroare2++;
                    cout << "Va rugam mai introduceti o data, de data asta un numar valid: ";
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cin >> nr_nou;
                }
            }
            cout<<"Cea mai mare valoare dintre cele doua numere este: ";
            if(numberInputStep->getNumar()<nr_nou)
            {
                cout<<nr_nou;
                cout<<endl;
                numberInputStep->setNumar(nr_nou);
            }
            else
            {
                cout<<numberInputStep->getNumar();
                cout<<endl;
                numberInputStep->setNumar(numberInputStep->getNumar());
            }

        }

    }

    int getEroare2() const
    {
        return eroare2;

    }

};

class FileInputStep : public Step
{
private:
    string descriere;
    string fisiertxt;

public:
    FileInputStep(string Textinput) : descriere(Textinput) {}

    string execute() const override
    {
        return  "Executare FILE input step: " + descriere ;
    }

    void run() override
    {
        cout<<"Executare FILE input step:"<<endl;

        cout << descriere << ": ";
        getline(cin, fisiertxt);
    }

    const string& getFileName() const
    {
        return fisiertxt;
    }
};

class CsvInputStep: public Step
{
private:
    string fisiercsv;
    string descriere;
public:
    CsvInputStep(string Textinput) : descriere(Textinput) {}

    string execute() const override
    {
        return   "Executare CSV input step: " + descriere ;
    }

    void run() override
    {
        cout<<"Executare CSV input step: "<<endl;
        cout << descriere << ": ";
        getline(cin, fisiercsv);
    }

    const string& getFileName2() const
    {
        return fisiercsv;
    }

};

class DisplayStep : public Step
{
private:
    FileInputStep* fileInputStep;
    CsvInputStep* csvinputstep;
    int ct1,ct2;
    fstream newfile;
    ifstream file;
    string noufisier;
    string noucsv;
public:
    DisplayStep(FileInputStep* fis,CsvInputStep* fis2,int ct1,int ct2) : fileInputStep(fis),csvinputstep(fis2),ct1(ct1),ct2(ct2) {}

    string execute() const override
    {
        return "Executare Display step:";
        return  "Pasul a fost retinut" ;
    }

    void run() override
    {

        cout<<"Executare Display step: ";
        if (fileInputStep != nullptr && ct1==1)
        {
            noufisier=fileInputStep->getFileName()+".txt";
            newfile.open(noufisier,ios::in); //open a file to perform read operation using file object
            if (newfile.is_open())  //checking whether the file is open
            {
                string tp;
                while(getline(newfile, tp))  //read data from file object and put it into string.
                {
                    cout << tp << "\n"; //print the data of the string
                }
                newfile.close(); //close the file object.
            }


        }

        if (csvinputstep != nullptr && ct2==1)
        {

            //newfile.open(csvinputstep->getFileName2(),ios::in); //open a file to perform read operation using file object

            file.open(csvinputstep->getFileName2());
            string line;
            getline(file, line);
            while (getline(file, line))
            {
                cout << line << endl;
            }
            file.close();

        }
    }


};

class OutputStep : public Step
{
private:
    string numefisier;
    string parcurgere;
    string title_fisier;
    string descriere_fisier;
    ofstream outfile;
    string extensie = ".txt";
    vector<Step*> steps;

public:
    OutputStep(const vector<Step*>& steps) : steps(steps) {}

    string execute() const override
    {
        return "Pasul a fost executat";
    }

    void run() override
    {
        // Afiseaza pasii anteriori
        cout<< "Executare Output step:"<<endl;

        cout << "Pasii anteriori sunt:" << endl;

        for (size_t i = 0; i < steps.size(); i++)
        {
            cout << steps[i]->execute() << endl;
        }

        cout << "Introduceti numele fisierului txt: ";
        getline(cin, numefisier);

        cout << "Introduceti titlul fisierului: ";
        getline(cin, title_fisier);

        cout << "Introduceti continutul fisierului: ";
        getline(cin, descriere_fisier);

        cout << "Fisierul a fost creat, cu datele dumnevoastara" << endl;

        numefisier = numefisier + extensie;

        // Adaugare date in fisier
        outfile.open(numefisier, ios_base::app);

        for (size_t i = 0; i < steps.size(); i++)
        {
            cout<<"Doriti sa afisati acest pas in fisierul txt? Sau preferati sa trecem la urmatorul?(Da/Nu)";
            getline(cin,parcurgere);

            if(parcurgere=="Da")
            {
                cout << "Vom afisa acest pas fisierul txt:" << steps[i]->execute() << endl;
                outfile << steps[i]->execute() << endl;
            }
            else
            {
                cout<< "Vom trece la pasul urmator"<<endl;

            }

            if(parcurgere!="Da" && parcurgere!="Nu")
            {
                cout<<"Va rugam sa reintroduceti mesajul deoarece , ati scris gresit";
                i--;
            }
        }

        outfile << title_fisier << endl;
        outfile << descriere_fisier << endl;
        outfile.close();
    }
};




int main()
{
    cout << "Bine ati venit la noi pe site!" << endl;
    cout << "Doriti sa creati un flow sau sa parcurgeti unul ?" << endl;
    cout << "1=Creeaza flow" << endl;
    cout << "2=Parcurgeti unul deja creat flow" << endl;

    vector<Step*> steps;
    vector<string> nume_flow;
    vector <vector<Step*>> flows;


    int eroare1Value=0;
    int eroare2Value=0;
    int start_flow=0;
    int nr_step_flow=0;
    int parcurgere_flow=0;
    int n=0;
    int skip;

    char c[1];
    cin >> c;
    cin.ignore();

    string numeflow;

    if (strcmp(c, "1") == 0)
    {
        string pas;
        cout<<"Va prezentam pasii pe care ii avem la dispozitia dumneavoastra:"<<endl;
        cout<<"1.Title step"<<endl;
        //cout<<"La Title step , sunteti nevoiti sa introduceti un titlu si un subtitlu"<<endl;

        cout<<"2.Text step"<<endl;
        //cout<<"La Text step , sunteti nevoiti sa introduceti un titlu si o coipe"<<endl;

        cout<<"3.Text input step"<<endl;
        //cout<<"La pasul Text input , sunteti nevoiti sa intrduceti o descriere, iar utilizatorul va intruduce un text (ex:nume)"<<endl;

        cout<<"4.Number input step"<<endl;
        //cout<<"La pasul Number input, sunteti obligat sa introduceti o descriere , care va fi completata de utilizator de un numar"<<endl;

        cout<<"5.Calculus step"<<endl;
        //cout<<"Acest pas , va realiza o operatie aleasa de dumneavoastra , combinata cu o valoare aleasa de utilizator"<<endl;

        cout<<"6.Display step"<<endl;
        //cout<<"Va afisa ce se afla in interiul unui fisier de tip txt sau csv , introdus anterior"<<endl;

        cout<<"7.Text file step"<<endl;
        //cout<<"La acest pas ,utilizatorul va specifica un fisier de tip txt , din care se vor extrage infomartii"<<endl;

        cout<<"8.Csv file step"<<endl;
        //cout<<"La acest pas ,utilizatorul va specifica un fisier de tip csv , din care se vor extrage infomartii"<<endl;

        cout<<"9.Output step"<<endl;
        //cout<<"Va afisa intr un fisier de tip txt , un titlu , o descrie si ce pasi doreste utilizatorul"<<endl;

        cout<<"10.END step"<<endl;
        //cout<<"Acest pas inchide programul de creare"<<endl;




        string titlu;
        string subtitlu;

        string titlut;
        string copie;

        string descriere1;

        string descriere2;

        string descriere3;

        string descriere4;

        string operatie;



        int ct1=0;
        int ct2=0;
        int ok;
        string repetare;


        FileInputStep* fileInputStep = nullptr;
        CsvInputStep*  csvinputstep=nullptr;
        while(repetare!="Nu")
        {
            cout<<"Puteti sa incepeti introducerea pasilor pe care ii doriti in formarea unui program!"<<endl;
            cout<<"->";
            getline(cin, pas);

            while (pas != "END step")
            {
                ok=0;
                if (pas == "Title step")
                {

                    cout << "Titlu: ";
                    getline(cin, titlu);
                    cout << "Subtitlu: ";
                    getline(cin, subtitlu);
                    steps.push_back(new TitleStep(titlu, subtitlu));
                    ok=1;

                }
                else if (pas == "Text step")
                {

                    cout << "Titlu: ";
                    getline(cin, titlut);
                    cout << "Copie: ";
                    getline(cin, copie);
                    steps.push_back(new TextStep(titlut, copie));
                    ok=1;

                }
                else if (pas == "Text input step")
                {

                    cout << "Descriere: ";
                    getline(cin, descriere1);
                    steps.push_back(new TextInputStep(descriere1));
                    ok=1;

                }
                else if (pas == "Number input step")
                {

                    cout << "Descriere: ";
                    getline(cin, descriere2);
                    steps.push_back(new NumberInputStep(descriere2));
                    ok=1;

                }
                else if (pas == "Calculus step")
                {

                    cout << "Operatie (adunare/scadere/inmultire/impartire/minim/maxim): ";
                    getline(cin, operatie);
                    while (true)
                    {
                        try
                        {
                            if (operatie != "adunare" && operatie != "scadere" && operatie != "inmultire" && operatie != "impartire" && operatie != "minim" && operatie != "maxim")
                                throw operatie;
                            else
                                break; // Ieși din bucla while dacă operatia este validă
                        }
                        catch (const string &e)
                        {
                            cout << "Nu ati introdus o operatie valida. Va rugam introduceti una dintre urmatoarele: adunare, scadere, inmultire, impartire, minim, maxim" << endl;
                            cout << "Introduceti operatia dorita: ";
                            getline(cin, operatie);
                        }
                    }


                    // Găsirea ultimului NumberInputStep pentru legătură
                    NumberInputStep* lastNumberInputStep = nullptr;
                    for (size_t i = 0; i < steps.size(); i++)
                    {
                        auto numInputStep = dynamic_cast<NumberInputStep*>(steps[i]);
                        if (numInputStep != nullptr)
                        {
                            lastNumberInputStep = numInputStep;
                        }
                    }

                    if (lastNumberInputStep != nullptr)
                    {
                        steps.push_back(new CalculStep(operatie, lastNumberInputStep));
                    }
                    else
                    {
                        cout << "Eroare: Nu exista niciun NumberInputStep definit anterior." << endl;
                    }
                    ok=1;


                }
                else if (pas == "Text file step")
                {

                    cout << "Descriere: ";
                    getline(cin, descriere3);
                    fileInputStep = new FileInputStep(descriere3);
                    steps.push_back(fileInputStep);
                    ok=1;
                    ct1=1;

                }
                else if (pas == "Csv file step")
                {


                    cout << "Descriere: ";
                    getline(cin, descriere4);
                    csvinputstep = new CsvInputStep(descriere4);
                    steps.push_back(csvinputstep);
                    ok=1;
                    ct2=1;

                }

                else if (pas == "Display step")
                {
                    //cout << "Pasul a fost retinut" << endl;
                    if ((fileInputStep != nullptr && ct1==1) || (csvinputstep != nullptr && ct2==1))
                    {
                        steps.push_back(new DisplayStep(fileInputStep,csvinputstep,ct1,ct2));
                        cout << "Pasul a fost retinut" << endl;
                        ct1=0;
                        ct2=0;

                    }
                    else
                    {
                        cout << "Eroare: Nu exista niciun fisire de tip csv sau txt definit anterior." << endl;


                    }
                    ok=1;


                }
                else if (pas == "Output step")
                {
                    cout<<"Va rugam introduceti datele:";
                    steps.push_back(new OutputStep(steps));
                    ok=1;

                }


                if(ok==0)
                    cout<<"Ne pare rau , nu ati tastat corect step-ul pe care doriti sa-l folositi. Va ruga mai introduceti o data !"<<endl;
                else
                    cout << "Introduceti urmatorul tip de pas sau 'END step' pentru a incheia: "<<endl;

                cout<<"->";
                getline(cin, pas);


            }


            cout<<"Va rugam introduceti un titlu reprezentativ creat de dumnevoastra: ";
            getline(cin, numeflow);
            nume_flow.push_back(numeflow);

            flows.push_back(steps);
            steps.clear();

            cout<<"Flow ul a fost cret la momentul : ";
            auto start = chrono::high_resolution_clock::now();
            auto startTime = chrono::high_resolution_clock::to_time_t(start);


            cout <<  ctime(&startTime);
            cout<<endl;



            cout<<"Doriti sa mai creati vreun flow?(Da/Nu):";
            getline(cin, repetare);

        }

        // DACA SE CERE RULAREA PROGRAMULUI CREAT :
        /*for (size_t i = 0; i < steps.size(); i++)
        {
            steps[i]->execute();
        }
        */

    }

    /*;

    for(i=0; i<flows.size(); i++)
    {
        for(j=0; j<flows[i].size(); j++)
            flows[i][j]->run();

    }
    */
    int i=0;
    int j=0;
    n=0;
    string confirmare;
    string numeflow2;


    cout<<"Doriti sa parcurgerti un program creat ?:";
    cout<<"(Da/Nu)"<<endl;
    getline(cin,confirmare);

    int numar;


    if(confirmare=="Da")
    {
        cout<<"Avem la dipozitia dvs aceste programe:"<<endl;
        for(i=0; i<nume_flow.size(); i++)
        {
            cout<<i<<"."<<nume_flow[i]<<endl;
        }

        cout<<"Pe care il doriti? Va rugam sa introduceti numarul care reprezinta numele programul:"<<endl;
        cin>>numar;
        cin.ignore(INT_MAX, '\n');
        cin.clear();

        i=0;
        for(i=0; i<flows.size(); i++)

        {
            bool repeat = true;
            start_flow=0;
            if(i==numar)

            {
                {
                    while (repeat)
                    {
                        parcurgere_flow=1;
                        try
                        {
                            if (i==numar)
                            {
                                start_flow++;



                                for(j=0; j<flows[i].size(); j++)
                                {
                                   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    cin.clear();
                                    string parcurgere;
                                    cout << "Doriti sa parcurgeti pasul cu nr." << j << " al acestui flow ? Sau sarim la urmatorul?(Da/Nu): ";
                                    getline(cin, parcurgere);

                                    if (parcurgere == "Da")
                                    {
                                        NumberInputStep* numberInputStep = dynamic_cast<NumberInputStep*>(steps[i]);
                                        CalculStep* calculInputStep=dynamic_cast<CalculStep*>(steps[i]);

                                        if (numberInputStep != nullptr)
                                        {
                                            flows[i][j]->run();
                                             cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                            eroare1Value += numberInputStep->getEroare1(); // Update eroare1Value

                                            cin.ignore(INT_MAX, '\n');
                                            continue;
                                        }

                                        else if(calculInputStep != nullptr)
                                        {
                                            flows[i][j]->run();
                                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                            eroare2Value += calculInputStep->getEroare2(); // Update eroare2Value
                                            cin.ignore(INT_MAX, '\n');

                                            continue;

                                        }
                                        else
                                        {
                                            flows[i][j]->run();
                                            continue;
                                        }

                                    }

                                    if (parcurgere == "Nu")
                                    {
                                        cout << "Vom trece la pasul urmator";
                                        skip++;
                                        parcurgere_flow=0;
                                        cin.ignore(INT_MAX, '\n');
                                    }

                                    if (parcurgere != "Da" && parcurgere != "Nu")
                                    {
                                        cout << "Va rugam sa reintroduceti mesajul , deoarece ati scris gresit"<<endl;
                                        cin.ignore(INT_MAX, '\n');
                                        j--;

                                    }

                                }

                                if (parcurgere_flow == 1)
                                    n++;

                                cout << "Felicitari ati parcurs programul cu succes!" << endl;

                                // Întrebare pentru repetare
                                cout << "Doriti sa mai parcurgeti inca o data acest flow? (Da/Nu): ";
                                getline(cin, confirmare);
                                cin.clear();
                                repeat = (confirmare == "Da");

                            }
                            else
                            {
                                throw runtime_error("Flow-ul nu exista!");
                            }
                        }
                        catch (const exception &e)
                        {

                            //cout << "Exceptie: " << e.what() << endl;
                            cout << "Doriti sa mai parcurgeti inca o data acest flow? (Da/Nu): ";
                            //getline(cin, confirmare);
                            repeat = (confirmare == "Da");
                        }
                    }
                }
            }
        }




        cout<<"Va vom prezenta o analiza a flow-ului parcurs :"<<endl;

        cout<<"1)";
        cout<<"De cate ori a fost parcurs un flow : ";
        cout<<start_flow;
        cout<<endl;


        cout<<"2)";
        cout<<"De cate ori a fost parcurs in intregime flow-ul:";
        cout<<n;
        cout<<endl;

        cout<<"3)";
        cout<<"Numarul de momente cand ati evitat un pas dintr-un flow este : ";
        cout<<skip;
        cout<<endl;

        cout<<"4)";
        cout<<"Media de erori a unui flow la parcurgerea acestuia : ";
        cout<<(eroare2Value+ eroare1Value)/start_flow;
        cout<<endl;


    }

    cout<<"Doriti sa stergeti un program creat anterior?:";

    cout<<"(Da/Nu)"<<endl;
    getline(cin,confirmare);



    if(confirmare=="Da")
    {
        cout<<"Avem la dipozitia dvs aceste programe:"<<endl;
        for(i=0; i<nume_flow.size(); i++)
        {
            cout<<i<<"."<<nume_flow[i]<<endl;
        }

        cout<<"Pe care il doriti? Va rugam sa introduceti numarul care reprezinta numele programul:"<<endl;
        cin>>numar;
        cin.ignore(INT_MAX, '\n');
        cin.clear();



        for(i=0; i<flows.size(); i++)
        {
            if(i==numar)
                for(j=0; j<flows[i].size(); j++)
                    delete flows[i][j];

            cout<<"Felicitari , ati sters programul nostru cu succes !"<<endl;
        }
    }
    cout<<endl;
    cout<<"Va multumim ca ne-ati folosit aplicatia noastra"<<endl;

    return 0;
}
