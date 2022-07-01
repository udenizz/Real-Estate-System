#include <iostream>
#include <string>
#include <string.h>
#include <fstream> 
#include <cstring>
#include <cstdlib>


using namespace std;

class RealEstate
{
	protected:
		int uprice;
		int systemprice;
		int m2;
		string location;
	public:
		static int counter;
		RealEstate()                   
		{
			uprice=0;
			m2=0;
			location="Default";
			systemprice=0;
			counter++;
		}
		int getCounter()
		{
			return counter;
		}
		void setSystemPrice(int n_systemprice)
		{
			systemprice=n_systemprice;
		}
		int getSystemPrice()
		{
			return systemprice;
		}
		void setuPrice(int n_uprice)
		{
			uprice=n_uprice;
		}
		int getuPrice()
		{
			return uprice;
		}
		void setM2(int n_m2)
		{
			m2=n_m2;
		}
		int getM2()
		{
			return m2;
		}
		void setLocation(string n_location)
		{
			location=n_location;
		}
		string getLocation()
		{
			return location;
		}
		virtual void calculatePrice()=0;
		virtual void uInput()=0;
		virtual void aInput()=0;
		virtual void Display()=0;
};
int RealEstate::counter=0;
class Home: public RealEstate 
{
	protected:
		int balcony;
		string security;
		string garden;
		string garage;
		string roomhall;
	public:
		Home()
		{
			balcony=0;
			security="Default";
			garden="Default";
			garage="Default";
			roomhall="Default";
		}
		int getBalcony()
		{
			return balcony;
		}
		void setBalcony(int n_balcony)
		{
			balcony=n_balcony;
		}
		string getSecurity()
		{
			return security;
		}
		void setSecurity(string n_security)
		{
			security=n_security;
		}
		string getGarden()
		{
			return garden;
		}
		void setGarden(string n_garden)
		{
			garden=n_garden;
		}
		string getGarage()
		{
			return garage;
		}
		void setGarage(string n_garage)
		{
			garage=n_garage;
		}
		string getRoomhall()
		{
			return roomhall;
		}
		void setRoomhall(string n_roomhall)
		{
			roomhall=n_roomhall;
		}
};
class Land: public RealEstate
{
	private:
		string improvement_area;
	public:
		Land()
		{
			improvement_area="Default";
		}
		string getImprovement_area()
		{
			return improvement_area;
		}
		void setImprovement_area(string n_improvement_area)
		{
			improvement_area=n_improvement_area;
		}
		void calculatePrice()
		{
			float loc,zn;
			int tempsysprice;
			if(location=="Cankaya" ||location=="cankaya" )
			{
			loc=2.5;
			}
			else if(location=="Mamak"||location=="mamak")
			{
				loc=1.3;
			}
			else if(location=="Etimesgut"||location=="etimesgut")
			{
				loc=1.6;
			}
			else if(location=="Yenimahalle"||location=="yenimahalle")
			{
				loc=2.0;
			}
			if(improvement_area=="Yes" || improvement_area=="yes")
			{
				zn=1.7;
			}
			else if(improvement_area=="No" || improvement_area=="no")
			{
				zn=0.7;
			}
			tempsysprice=loc*zn*m2*300;
			setSystemPrice(tempsysprice);
		}
		void uInput()
		{
			string temp;
			int temp1;
			cout<<"Enter location of land which is afforded by you:";
			cin>>temp;
			setLocation(temp);
			cout<<"Enter m2 of land which is afforded by you: ";
			cin>>temp1;
			setM2(temp1);
			cout<<"Do you want improved area which is afforded by you(yes/no):";
			cin>>temp;
			setImprovement_area(temp);
			cout<<"Enter price of land which is afforded by you:";
			cin>>temp1;
			setuPrice(temp1);
		}
		void Display()
		{
			cout<<"-------------------"<<endl;
			cout<<"Land location:"<<getLocation()<<endl;		
			cout<<"Land m2 is:"<<getM2()<<endl;
			cout<<"Is land improvement area:"<<getImprovement_area()<<endl;
			cout<<"Land price is:"<<getuPrice()<<endl;
			cout<<"-------------------"<<endl;
		}
		void aInput()
		{
			string temp;
            int temp1;
            cout<<"Enter location of land which is sold by you:";
            cin>>temp;
            setLocation(temp);
            cout<<"Enter m2 of land which is sold by you:";
            cin>>temp1;
            setM2(temp1);
            cout<<"Is this land an improved area (yes/no)?";
            cin>>temp;
            setImprovement_area(temp);
            cout<<"Enter price of land which is sold by you:";
            cin>>temp1;
            setuPrice(temp1);
            calculatePrice();
            if(getSystemPrice()>getuPrice()+10000)
            {
                cout<<"Your price is lower than recommended price."<<endl;
            }
            else if(getSystemPrice()<getuPrice()-10000)
            {
                cout<<"Your price is higher than recommended price."<<endl;
            }
            else
            {
                cout<<"Your price is close by recommended price."<<endl;
            }
            cout<<"Dou you want to change your price(yes/no)?";
            cin>>temp;
            if(temp=="yes")
            {
                cout<<"Enter price of Land which is sold by you:";
                cin>>temp1;
                setuPrice(temp1);
            }
		}
};

class Villa: public Home
{
	private:
		int vfloor;
		string pool;
	public:
		Villa();
		void setVfloor(int vfloor);
		void setPool(string pool); 
		int getVfloor();
		string getPool();
		void calculatePrice();
		void uInput();
		void aInput();
		void Display();
};

Villa::Villa()
{
	vfloor=0;
	pool="Default";
}
void Villa::setVfloor(int vfloor)
{
	Villa::vfloor=vfloor;
}
void Villa::setPool(string pool)
{
	Villa::pool=pool;
}
int Villa::getVfloor()
{
	return vfloor;
}
string Villa::getPool()
{
	return pool;
}
void Villa::calculatePrice()
{
	float loc,pl,sec,grg,grd,blc;
	int tempsysprice;
	if(location=="Cankaya" ||location=="cankaya" )
	{
		loc=3.0;
	}
	else if(location=="Mamak"||location=="mamak")
	{
		loc=1.5;
	}
	else if(location=="Etimesgut"||location=="etimesgut")
	{
		loc=1.8;
	}
	else if(location=="Yenimahalle"||location=="yenimahalle")
	{
		loc=2.4;
	}
	if(pool=="Yes" || pool=="yes")
	{
		pl=2.0;
	}
	else if(pool=="No" || pool=="no")
	{
		pl=1.0;
	}
	if(security=="Yes" || security=="yes")
	{
		sec=1.1;
	}
	else if(security=="No" || security=="no")
	{
		sec=1.0;
	}
	if(garage =="Yes" || garage=="yes")
	{
		grg=1.1;
	}
	else if(garage =="No" || garage=="no")
	{
		grg=1.0;
	}
	if(garden=="Yes" || garden=="yes")
	{
		grd=1.1;
	}
	else if(garden=="No" || garden=="no")
	{
		grd=1.0;
	}
	if(balcony>0)
	{
		blc=1.1;
	}
	else
	{
		blc=1.0;
	}
	tempsysprice=loc*pl*sec*grg*grd*blc*m2*800;
	setSystemPrice(tempsysprice);
}
void Villa::uInput()
{
	string temp;
	int temp1;
	cout<<"Enter a location of villa which is afforded bu you: ";
	cin>>temp;
	setLocation(temp);
	cout<<"Enter m2 of villa do you want: ";
	cin>>temp1;
	setM2(temp1);
	cout<<"Enter how many rooms and salons(ex.'3+1'): ";
	cin>>temp;
	setRoomhall(temp);
	cout<<"Do you want a garage belongs to your villa (yes/no): " ;
	cin>>temp;
	setGarage(temp);
	cout<<"Do you want a garden belongs to your villa (yes/no): ";
	cin>>temp;
	setGarden(temp);
	cout<<"Do you want a security belongs to your villa (yes/no): ";
	cin>>temp;
	setSecurity(temp);
	cout<<"How many balconies do you want: ";
	cin>>temp1;
	setBalcony(temp1);
	cout<<"Do you want have a pool belongs to your villa (yes/no): ";
	cin>>temp;
	setPool(temp);
	cout<<"Enter price of villa which can afforded by you: ";
	cin>>temp1;
	setuPrice(temp1);
}
void Villa::aInput()
{
	string temp;
	int temp1;
	cout<<"Enter a location of villa which is sold by you: ";
	cin>>temp;
	setLocation(temp);
	cout<<"Enter m2 of villa is sold by you: ";
	cin>>temp1;
	setM2(temp1);
	cout<<"Enter how many rooms and salons(ex.'3+1'): ";
	cin>>temp;
	setRoomhall(temp);
	cout<<"Enter a garage if your villa has (yes/no): " ;
	cin>>temp;
	setGarage(temp);
	cout<<"Enter a garden if your villa has (yes/no): ";
	cin>>temp;
	setGarden(temp);
	cout<<"Enter a security if your villa has (yes/no): ";
	cin>>temp;
	setSecurity(temp);
	cout<<"How many balconies do your villa has: ";
	cin>>temp1;
	setBalcony(temp1);
	cout<<"Enter a pool if your villa has (yes/no): ";
	cin>>temp;
	setPool(temp);
	cout<<"Enter price of villa which is sold by you: ";
	cin>>temp1;
	setuPrice(temp1);
	calculatePrice();
	if(getSystemPrice()>getuPrice()+10000)
    {
        cout<<"Your price is lower than recommended price."<<endl;
    }
    else if(getSystemPrice()<getuPrice()-10000)
    {
        cout<<"Your price is higher than recommended price."<<endl;
    }
    else
    {
        cout<<"Your price is close by recommended price."<<endl;
    }
    cout<<"Dou you want to change your price(yes/no)?";
    cin>>temp;
    if(temp=="yes")
    {
    	cout<<"Enter price of Villa which is sold by you:";
        cin>>temp1;
        setuPrice(temp1);
    }
}
void Villa::Display()
{
	cout<<"-------------------"<<endl;
	cout<<"Villa location:"<<getLocation()<<endl;
	cout<<"Villa m2 is:"<<getM2()<<endl;
	cout<<"Number of Rooms and Salons: "<<getRoomhall()<<endl;
	cout<<"Garage: "<<getGarage()<<endl;
	cout<<"Garden: "<<getGarden()<<endl;
	cout<<"Security: "<<getSecurity()<<endl;
	cout<<"Number of balconies: "<<getBalcony()<<endl;
	cout<<"Pool: "<<getPool()<<endl;
	cout<<"Villa price is:"<<getuPrice()<<endl;
	cout<<"-------------------"<<endl;
}
class Apartment : public Home
{
	private:
		int afloat;
		string elevator;
	public:
		Apartment();
		void setAfloat(int afloat);
		void setElevator(string elevator);
		int getAfloat();
		string getElevator();
		void calculatePrice();
		void uInput();
		void Display();
		void aInput();
};

Apartment::Apartment()
{
	afloat=0;
	elevator="Default";
}
void Apartment::setAfloat(int afloat)
{
	Apartment::afloat=afloat;
}
void Apartment::setElevator(string elevator)
{
	Apartment::elevator=elevator;
}
int Apartment::getAfloat()
{
	return afloat;
}
string Apartment::getElevator()
{
	return elevator;
}
void Apartment::calculatePrice()
{
	float loc,sec,grg,grd,blc;
	int tempsysprice;
	if(location=="Cankaya" ||location=="cankaya" )
	{
		loc=2.8;
	}
	else if(location=="Mamak"||location=="mamak")
	{
		loc=1.4;
	}
	else if(location=="Etimesgut"||location=="etimesgut")
	{
		loc=1.7;
	}
	else if(location=="Yenimahalle"||location=="yenimahalle")
	{
		loc=2.3;
	}
	if(security=="Yes" || security=="yes")
	{
		sec=1.1;
	}
	else if(security=="No" || security=="no")
	{
		sec=1.0;
	}
	if(garage =="Yes" || garage=="yes")
	{
		grg=1.1;
	}
	else if(garage =="No" || garage=="no")
	{
		grg=1.0;
	}
	if(garden=="Yes" || garden=="yes")
	{
		grd=1.1;
	}
	else if(garden=="No" || garden=="no")
	{
		grd=1.0;
	}
	if(balcony>0)
	{
		blc=1.1;
	}
	else
	{
		blc=1.0;
	}
	tempsysprice=loc*sec*grg*grd*blc*m2*500;
	setSystemPrice(tempsysprice);
}
void Apartment::uInput()
{
	string temp;
	int temp1;
	cout<<"Enter a location of apartment which is afforded by you: ";
	cin>>temp;
	setLocation(temp);
	cout<<"Enter m2 of apartment do you want: ";
	cin>>temp1;
	setM2(temp1);
	cout<<"Enter apartment floor which is afforded by you:";
	cin>>temp1;
	setAfloat(temp1);
	cout<<"Enter how many rooms and salons(ex.'3+1'): ";
	cin>>temp;
	setRoomhall(temp);
	cout<<"Do you want a garage belongs to your apartment (yes/no): " ;
	cin>>temp;
	setGarage(temp);
	cout<<"Do you want a garden belongs to your apartment (yes/no): ";
	cin>>temp;
	setGarden(temp);
	cout<<"Do you want a security belongs to your apartment (yes/no): ";
	cin>>temp;
	setSecurity(temp);
	cout<<"How many balconies do you want: ";
	cin>>temp1;
	setBalcony(temp1);
	cout<<"Do you want have a elevator belongs to your apartment (yes/no): ";
	cin>>temp;
	setElevator(temp);
	cout<<"Enter price of apartment which can afforded by you: ";
	cin>>temp1;
	setuPrice(temp1);
}
void Apartment::Display()
{
	cout<<"-------------------"<<endl;
	cout<<"Apartment location:"<<getLocation()<<endl;
	cout<<"Apartment  m2 is:"<<getM2()<<endl;
	cout<<"Apartment floor is:"<<getAfloat()<<endl;
	cout<<"Number of Rooms and Salons: "<<getRoomhall()<<endl;
	cout<<"Garage: "<<getGarage()<<endl;
	cout<<"Garden: "<<getGarden()<<endl;
	cout<<"Security: "<<getSecurity()<<endl;
	cout<<"Number of balconies: "<<getBalcony()<<endl;
	cout<<"Elevator: "<<getElevator()<<endl;
	cout<<"Apartment  price is:"<<getuPrice()<<endl;
	cout<<"-------------------"<<endl;
}
void Apartment::aInput()
{
	string temp;
    int temp1;
    cout<<"Enter a location of apartment which is sold by you: ";
    cin>>temp;
    setLocation(temp);
    cout<<"Enter m2 of apartment which is sold by you: ";
    cin>>temp1;
    setM2(temp1);
    cout<<"Enter apartment floor which is sold by you:";
	cin>>temp1;
	setAfloat(temp1);
    cout<<"Enter how many rooms and salons(ex.'3+1'): ";
    cin>>temp;
    setRoomhall(temp);
    cout<<"Has yout apartment a garage(yes/no): " ;
    cin>>temp;
    setGarage(temp);
    cout<<"Has yout apartment a garden(yes/no): ";
    cin>>temp;
    setGarden(temp);
    cout<<"Has your apartment a security (yes/no): ";
    cin>>temp;
    setSecurity(temp);
    cout<<"How many balconies your apartment has: ";
    cin>>temp1;
    setBalcony(temp1);
    cout<<"Has your apartment an elevator (yes/no): ";
    cin>>temp;
    setElevator(temp);
    cout<<"Enter price of apartment which which is sold by you: ";
    cin>>temp1;
    setuPrice(temp1);
    calculatePrice();
    if(getSystemPrice()>getuPrice()+10000)
    {
        cout<<"Your price is lower than recommended price."<<endl;
    }
    else if(getSystemPrice()<getuPrice()-10000)
    {
        cout<<"Your price is higher than recommended price."<<endl;
    }
    else
    {
        cout<<"Your price is close by recommended price."<<endl;
    }
    cout<<"Dou you want to change your price(yes/no)?";
    cin>>temp;
    if(temp=="yes")
    {
        cout<<"Enter price of apartment which which is sold by you:";
        cin>>temp1;
        setuPrice(temp1);
    }
}

int main()
{
	int select,select1,select2,select3,select4;
	int user,admin;
	int landcounter=0;
	int apartcounter=0;
	int villacounter=0;
	int filecounter=0;
	Land land2[100];
	Villa villa2[100];
	Apartment apart2[100];
	string word;
	fstream file;
	file.open("land.txt", ios::in);
	if(!file)
	{
		cout<<"No such a file!";
		return 0;
	}
	else
	{
		while(file>>word)
		{
			if(filecounter==0)
			{
				string temp=word;
				land2[landcounter].setLocation(temp);
				filecounter++;
			}
			else if(filecounter==1)
			{
				string temp2=word;
				int temp1=atoi(temp2.c_str());
				land2[landcounter].setM2(temp1);
				filecounter++;
			}
			else if(filecounter==2)
			{
				string temp5=word;
				land2[landcounter].setImprovement_area(temp5);				
				filecounter++;
			}
			else if(filecounter==3)
			{
				string temp4=word;
				int temp1=atoi(temp4.c_str());
				land2[landcounter].setuPrice(temp1);
				filecounter++;
			}
			if(filecounter==4)
			{
				filecounter=0;
				landcounter++;
			}
		}		
	}
	file.close();
	fstream file1;
	file1.open("apart.txt", ios::in);
	filecounter=0;
	if(!file1)
	{
		cout<<"No such a file!";
		return 0;
	}
	else
	{
		while(file1>>word)
		{
			if(filecounter==0)
			{
				string temp=word;
				apart2[apartcounter].setLocation(temp);
				filecounter++;
			}
			else if(filecounter==1)
			{
				string temp=word;
				int temp1=atoi(temp.c_str());
				apart2[apartcounter].setM2(temp1);
				filecounter++;
			}
			else if(filecounter==2)
			{
				string temp=word;
				int temp1=atoi(temp.c_str());
				apart2[apartcounter].setAfloat(temp1);
				filecounter++;
			}
			else if(filecounter==3)
			{
				string temp=word;
				int temp1=atoi(temp.c_str());
				apart2[apartcounter].setBalcony(temp1);
				filecounter++;
			}
			else if(filecounter==4)
			{
				string temp=word;
				apart2[apartcounter].setElevator(temp);
				filecounter++;
			}
			else if(filecounter==5)
			{
				string temp=word;
				apart2[apartcounter].setGarage(temp);
				filecounter++;
			}
			else if(filecounter==6)
			{
				string temp=word;
				apart2[apartcounter].setGarden(temp);
				filecounter++;
			}
			else if(filecounter==7)
			{
				string temp=word;
				apart2[apartcounter].setRoomhall(temp);
				filecounter++;
			}
			else if(filecounter==8)
			{
				string temp=word;
				apart2[apartcounter].setSecurity(temp);
				filecounter++;
			}
			else if(filecounter==9)
			{
				string temp=word;
				int temp1=atoi(temp.c_str());
				apart2[apartcounter].setuPrice(temp1);
				filecounter++;
			}
			if(filecounter==10)
			{
				filecounter=0;
				apartcounter++;
			}
		}
	}
	file1.close();
	fstream file2;
	file2.open("villa.txt", ios::in);
	filecounter=0;
	if(!file2)
	{
		cout<<"No such a file!";
		return 0;
	}
	else
	{
		while(file2>>word)
		{
			if(filecounter==0)
			{
				string temp=word;
				villa2[villacounter].setLocation(temp);
				filecounter++;
			}
			else if(filecounter==1)
			{
				string temp=word;
				int temp1=atoi(temp.c_str());
				villa2[villacounter].setM2(temp1);
				filecounter++;
			}
			else if(filecounter==2)
			{
				string temp=word;
				int temp1=atoi(temp.c_str());
				villa2[villacounter].setVfloor(temp1);
				filecounter++;
			}
			else if(filecounter==3)
			{
				string temp=word;
				int temp1=atoi(temp.c_str());
				villa2[villacounter].setBalcony(temp1);
				filecounter++;
			}
			else if(filecounter==4)
			{
				string temp=word;
				villa2[villacounter].setGarage(temp);
				filecounter++;
			}
			else if(filecounter==5)
			{
				string temp=word;
				villa2[villacounter].setGarden(temp);
				filecounter++;
			}
			else if(filecounter==6)
			{
				string temp=word;
				villa2[villacounter].setRoomhall(temp);
				filecounter++;
			}
			else if(filecounter==7)
			{
				string temp=word;
				villa2[villacounter].setSecurity(temp);
				filecounter++;
			}
			else if(filecounter==8)
			{
				string temp=word;
				villa2[villacounter].setPool(temp);
				filecounter++;
			}
			else if(filecounter==9)
			{
				string temp=word;
				int temp1=atoi(temp.c_str());
				villa2[villacounter].setuPrice(temp1);
				filecounter++;
			}
			if(filecounter==10)
			{
				filecounter=0;
				villacounter++;
			}
		}
	}
	file2.close();
	cout<<"--------------WELCOME REAL ESTATE PROGRAM--------------"<<endl;
	cout<<"1-If you want to buy property press (1)\n2-If you want to sell property press (2)\n3-Exit (3)";
	cin>>select;
	while(select!=3)
	{
		if(select==1)
		{
			cout<<"Choose what do you want to buy\n1-Land\n2-Apartment\n3-Villa\n4-Exit";
			cin>>select1;
			while(select1!=4)
			{	
				
				if(select1==1)
				{
					int index=0;
					int controller=0;
					cout<<"If you want to see land which are on sale in the system press (1).If you dont want see press (2)";
					cin>>select3;
					if(select3==1)
					{
						for(int i=0; i<landcounter; i++)
						{
							land2[i].Display();
						}
					}
					Land *land;
					land=new Land();
					land->uInput();
					land->calculatePrice();
					for(int i=0;i<landcounter;i++)//buradaki counterlar land2 arrayinin i�indeki toplam sat�� landinin say�s�n� tutucak satt���m�zda a�a��da k���ltecek!!
					{
						if(land->getLocation()==land2[i].getLocation())
						{
							if(land->getuPrice()==land2[i].getuPrice())
							{
								if(land->getM2()==land2[i].getM2())
								{
									index=i;
									controller=1;//for sonunda iste�inizeg�re yer bulamad�k mesaj� vermek amac�m�z!!!
									land->Display();
									cout<<"\n\nThis land is the best matching for you!!!"<<endl;
									cout<<"Will you buy this land?\n1-Press 1 for buy\n2-Press 2 for searching another property:";
									cin>>select2;
									if(select2==1)
									{
										for(int j=index;j<landcounter;j++)
										{
											land2[j]=land2[j+1];
										}
										landcounter--;
										cout<<"You successfully bought this Land!!"<<endl;
										select1=4;
										i=landcounter;
									}
									else if(select2==2)
									{
										cout<<"Now you are searching new properties!!!"<<endl;
										select1=4;
										i=landcounter;
									}
								}
							}
							else if(land->getuPrice()>land2[i].getuPrice())
							{
								land2[i].Display();
							}
						}
						if(select1==4)
						{
							exit;
						}
					}
					if(controller!=1)
					{
						cout<<"In this Lands did not match with your searching land!!"<<endl;
						cout<<"You can look another Lands which are lower priced !!!"<<endl;
					}
				}
				else if(select1==2)
				{
					int index=0;
					int controller=0;
					cout<<"If you want to see apartment which are on sale in the system press (1).If you dont want see press (2)";
					cin>>select3;
					if(select3==1)
					{
						for(int i=0;i<apartcounter;i++)
						{
							apart2[i].Display();
						}
					}
					Apartment apart;
					apart.uInput();
					apart.calculatePrice();
					for(int i=0;i<apartcounter;i++)
					{
						if(apart.getLocation()==apart2[i].getLocation())
						{
							if(apart.getM2()==apart2[i].getM2())
							{
								if(apart.getuPrice()==apart2[i].getuPrice())
								{
									if(apart.getBalcony()==apart2[i].getBalcony())
									{
										if(apart.getSecurity()==apart2[i].getSecurity())
										{
											if(apart.getGarden()==apart2[i].getGarden())
											{
												if(apart.getGarage()==apart2[i].getGarage())
												{
													if(apart.getRoomhall()==apart2[i].getRoomhall())
													{
														if(apart.getElevator()==apart2[i].getElevator())
														{
															index=i;
															controller=1;
															apart.Display();
															cout<<"\n\nThis apart is the best matching for you!!!"<<endl;
															cout<<"Will you buy this apart?\n1-Press 1 for buy\n2-Press 2 for searching another property:";
															cin>>select2;
															if(select2==1)
															{
																for(int j=index;j<apartcounter;j++)
																{
																	apart2[j]=apart2[j+1];
																}
																apartcounter--;
																cout<<"You successfully bought this Apart!!"<<endl;
																select1=4;
															}
															else if(select2==2)
															{
																cout<<"Now you are searching new properties!!!"<<endl;
																select1=4;
															}
														}
													}
												}
											}
										}
									}	
								}
								else if(apart.getuPrice()>apart2[i].getuPrice())
								{
									apart2[i].Display();
								}
							}
						}
					}
					if(controller!=1)
					{
						cout<<"In this Aparts did not match with your searching land!!"<<endl;
						cout<<"You can look another Aparts which are lower priced !!!"<<endl;
					}
				}
				else if(select1==3)
				{
					int index=0;
					int controller=0;
					cout<<"If you want to see villa which are on sale in the system press (1).If you dont want see press (2)";
					cin>>select3;
					if(select3==1)
					{
						for(int i=0;i<villacounter;i++)
						{
							villa2[i].Display();
						}
					}
					Villa villa;
					villa.uInput();
					villa.calculatePrice();
					for(int i=0;i<villacounter;i++)
					{
						if(villa.getLocation()==villa2[i].getLocation())
						{
							if(villa.getM2()==villa2[i].getM2())
							{
								if(villa.getuPrice()==villa2[i].getuPrice())
								{
									if(villa.getBalcony()==villa2[i].getBalcony())
									{
										if(villa.getSecurity()==villa2[i].getSecurity())
										{
											if(villa.getGarden()==villa2[i].getGarden())
											{
												if(villa.getGarage()==villa2[i].getGarage())
												{
													if(villa.getRoomhall()==villa2[i].getRoomhall())
													{
														if(villa.getPool()==villa2[i].getPool())
														{
															index=i;
															controller=1;
															villa.Display();
															cout<<"\n\nThis villa is the best matching for you!!!"<<endl;
															cout<<"Will you buy this villa?\n1-Press 1 for buy\n2-Press 2 for searching another property:";
															cin>>select3;
															if(select3==1)
															{
																for(int j=index;j<villacounter;j++)
																{
																	villa2[j]=villa2[j+1];
																}
																villacounter--;
																cout<<"You successfully bought this villa!!"<<endl;
																select1=4;
															}
															else if(select2==2)
															{
																cout<<"Now you are searching new properties!!!"<<endl;
																select1=4;
															}
														}
													}
												}
											}
										}
									}	
								}
								else if(villa.getuPrice()>villa2[i].getuPrice())
								{
									villa2[i].Display();
								}
							}
						}
					}
					if(controller!=1)
					{
						cout<<"In this villa did not match with your searching Villa!!"<<endl;
						cout<<"You can look another villa which are lower priced !!!"<<endl;
					}
				}
			}
			}
			else if(select==2)
			{
				cout<<"Choose what do you want to sell\n1-Land\n2-Apartment\n3-Villa\n4-Exit";
				cin>>select1;
				while(select1!=4)
				{
					if(select1==1)
					{
						Land sland;
						sland.aInput();
						land2[landcounter].setLocation(sland.getLocation());
						land2[landcounter].setM2(sland.getM2());
						land2[landcounter].setuPrice(sland.getuPrice());
						land2[landcounter].setImprovement_area(sland.getImprovement_area());
						landcounter++;
						select1=4;
					}
					else if(select1==2)
					{
						Apartment sapart;
						sapart.aInput();
						apart2[apartcounter].setLocation(sapart.getLocation());
						apart2[apartcounter].setM2(sapart.getM2());
						apart2[apartcounter].setuPrice(sapart.getuPrice());
						apart2[apartcounter].setAfloat(sapart.getAfloat());
						apart2[apartcounter].setBalcony(sapart.getBalcony());
						apart2[apartcounter].setElevator(sapart.getElevator());
						apart2[apartcounter].setGarage(sapart.getGarage());
						apart2[apartcounter].setGarden(sapart.getGarden());
						apart2[apartcounter].setRoomhall(sapart.getRoomhall());
						apart2[apartcounter].setSecurity(sapart.getSecurity());
						apartcounter++;
						select1=4;
					}
					else if(select1==3)
					{
						Villa svilla;
						svilla.aInput();
						villa2[villacounter].setLocation(svilla.getLocation());
						villa2[villacounter].setM2(svilla.getM2());
						villa2[villacounter].setuPrice(svilla.getuPrice());
						villa2[villacounter].setVfloor(svilla.getVfloor());
						villa2[villacounter].setBalcony(svilla.getBalcony());
						villa2[villacounter].setPool(svilla.getPool());
						villa2[villacounter].setGarage(svilla.getGarage());
						villa2[villacounter].setGarden(svilla.getGarden());
						villa2[villacounter].setRoomhall(svilla.getRoomhall());
						villa2[villacounter].setSecurity(svilla.getSecurity());
						villacounter++;
						select1=4;
					}
				}
			}
			cout<<"1-If you want to buy property press (1)\n2-If you want to sell property press (2)\n3-Exit (3)";
			cin>>select;
		}
	
	return 0;
}

