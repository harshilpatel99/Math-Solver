#include<iostream>
#include<iomanip>
#include<fstream>
#include<stdlib.h>
using namespace std;
#include<cmath>
#include<string.h>
#define max 100
#define PI 3.14159265359
int top=-1;
float s[max];
float e[max];
void push(float d)
{
	if(top==(max-1))
	{
		cout<<"stack is full";
	}
	else
	{
		top++;
		s[top]=d;
	}
	
}
float pop()
{
	if(top==-1)
	{
		cout<<"stack is empty";
	}
	else
	{
		return s[top--];
	}
}

//evaluation stack

void epush(float d)
{
	if(top==(max-1))
	{
		cout<<"stack is full";
	}
	else
	{
		top++;
		e[top]=d;
		
	}
	
}
float epop()
{
	if(top==-1)
	{
		cout<<"stack is empty";
	}
	else
	{
		return e[top--];
	}
}

//

int priority(int d)
{
	if(d==8)								// (
	{
		return 0;							 
	}
	if(d==1||d==3)							// +,-
	{
		return 1;
	}
	if(d==2||d==4||d==5||d==6)				// *,/, %,^
	{
		return 2;
	}
	if(d==7||d==10||d==11||d==12||d==13||d==14)	// r,e,s,c,t
	{
		return 3;
	}
}
void end_line()
{
	int i;
	for(i=0;i<100;i++)
	{
		cout<<"_";
	}
}

void design()
{
	int i;
	for(i=0;i<100;i++)
	{
		cout<<"*";
	}
}
float f(float a,float b,float c,float d,float x)
{
	float ans;
	ans=((a*x*x*x)+(b*x*x)+(c*x)+d);
	return ans;
}

// polynomial equation


void poly()
{
	float i,j,p,q,x,a,b,c,d,f1,f2;
	cout<<"enter your polynomial equation: ";
	cin>>a>>b>>c>>d;
	cout<<endl;
	for(i=-5;i<5;i++)
	{
		f1=f(a,b,c,d,i);
		f2=f(a,b,c,d,i+1);
		if(f1*f2<0)
		{
			p=i;
			q=i+1;
		}
		else if(f1==0)
		{
			cout<<"one of the solution of your equation is: "<<i<<" and its value is: "<<f(a,b,c,d,i)<<endl;
		}
	}
	do
	{
		x=q-(f(a,b,c,d,q)/((f(a,b,c,d,q)-f(a,b,c,d,p))/(q-p)));
		p=q;
		q=x;
	}while(f(a,b,c,d,x)<-0.0001||f(a,b,c,d,x)>0.0001);
	cout<<"one of the solution of your equation is: "<<x<<" and its value is: "<<f(a,b,c,d,x)<<endl;
	end_line();
}


//arithmetic equation


float arithmetic(char p[max])
{
	char c[max],n[max];
	int i,j=0;
	float d;
	int k=0,cop=0,cbr=0,cex=0,cp,q=0,r=0,v;				   //parb=parallel b
	char temp[10];											//getting two or more digit numbers
	fflush(stdin);
	strcpy(c,p);
	for(i=0;i<strlen(c);i++)								//White Spaces are been removed
	{
		if(c[i]!=' ')
		{
			n[k]=c[i];
			k++;
		}
		else if(c[i]=='=')
		{
			break;
		}
	}
	n[k]='\0';
//	cout<<"\n"<<n;
	for(i=0;i<strlen(n);i++)
	{
		if(i==0&&(n[i]=='+'||n[i]=='-'))
		{
			;
		}
		else if(n[i]=='*'||n[i]=='+'||n[i]=='-'||n[i]=='/'||n[i]=='^'||n[i]=='%'||n[i]=='r')
		{
			cop++;											//count operators
		}
		else if(n[i]=='('||n[i]==')')
		{
			cbr++;											//count brackets
		}
		else if(n[i]=='l'||n[i]=='e'||n[i]=='s'||n[i]=='c'||n[i]=='t')
		{
			cex++;											//counting single digit operators(Explicitly made operators)
		}
	}
	//cout<<cbr;
	cp=2*cop+1;												 // a+b+c+d -> 3 operator and 4 variables and have no brackets so 0 cbr, total array size is 7
	cp=cp+cbr;	
	cp=cp+cex;
	//cout<<strlen(n);
	float main[cp],opr[cp],b[cp-cbr],parb[cp-cbr],tval;		//main array contains only real digits while operators are made 0 for a while //opr array contains only operators while numbers are 0		          		
	for(i=0;i<strlen(n)+1;i++)
	{
		if(n[i]=='('||n[i]==')'||n[i]=='l'||n[i]=='e'||n[i]=='s'||n[i]=='c'||n[i]=='t')			
		{
			if(n[i]=='(')
			{
				v=8;
				main[r]=0;
				opr[r]=v;
				r++;
			}
			else if(n[i]==')')
			{
				v=9;
				main[r]=0;
				opr[r]=v;
				r++;
			}
			else if(n[i]=='l')
			{
				v=10;
				main[r]=0;
				opr[r]=v;
				r++;
			}
			else if(n[i]=='e')
			{
				v=11;
				main[r]=0;
				opr[r]=v;
				r++;
			}
			else if(n[i]=='s')
			{
				v=12;
				main[r]=0;
				opr[r]=v;
				r++;
			}
			else if(n[i]=='c')
			{
				v=13;
				main[r]=0;
				opr[r]=v;
				r++;
			}
			else if(n[i]=='t')
			{
				v=14;
				main[r]=0;
				opr[r]=v;
				r++;
			}
		}
		else if(n[i]=='*'||n[i]=='+'||n[i]=='-'||n[i]=='/'||n[i]=='^'||n[i]=='%'||n[i]=='r'||n[i]=='\0')
		{
				if(i==0&&(n[i]=='+'||n[i]=='-'))					//SPECIAL CASE -a+b
				{
					temp[q]=n[i];
					q++;
				}				
				else if(n[i]=='+')
				{
					v=1;
					main[r]=0;
					opr[r]=v;
					r++;
				}
				else if(n[i]=='*')
				{
					v=2;
					main[r]=0;
					opr[r]=v;
					r++;
				}
				else if(n[i]=='-')
				{
					v=3;
					main[r]=0;
					opr[r]=v;
					r++;
				}
				else if(n[i]=='/')
				{
					v=4;
					main[r]=0;
					opr[r]=v;
					r++;
				}
				else if(n[i]=='%')
				{
					v=5;
					main[r]=0;
					opr[r]=v;
					r++;
				}
				else if(n[i]=='^')
				{
					v=6;
					main[r]=0;
					opr[r]=v;
					r++;
				}
				else if(n[i]=='r')
				{
					v=7;
					main[r]=0;
					opr[r]=v;
					r++;
				}			
		}		
		else										//handling of two or more digit number is done here...
		{
			temp[q]=n[i];
			q++;
			if(n[i+1]=='('||n[i+1]==')'||n[i+1]=='l'||n[i+1]=='e'||n[i+1]=='s'||n[i+1]=='c'||n[i+1]=='t'||n[i+1]=='*'||n[i+1]=='+'||n[i+1]=='-'||n[i+1]=='/'||n[i+1]=='^'||n[i+1]=='%'||n[i+1]=='r'||n[i+1]=='\0')
			{	
				temp[q]='\0';
				tval=atof(temp);
				//cout<<tval<<endl;
				q=0;
				main[r]=tval;
				opr[r]=0;
				r++;
			}
			
		}
	}
	////////////////////////////////////////////////////////////////////////////////////////
	/*for(i=0;i<cp;i++)
	{
		cout<<main[i];							//prints main float array		//correct everytime
	}
	cout<<endl;
	for(i=0;i<cp;i++)
	{
		cout<<opr[i];							//prints operator array			//correct everytime
	}
	cout<<endl;*/
	//postfix evaluation of main string
	////////////////////////////////////////////////////////////////////////////////////////
	j=0;
	for(i=0;i<cp;i++)
	{
		if(main[i]==0 && opr[i]!=0 && opr[i]!=8 && opr[i]!=9)
		{
			while(priority(s[top])>=priority(opr[i]))
			{
				b[j]=pop();
				j++;
			}
			push(opr[i]);
		}
		else if(opr[i]==8)
		{
			push(opr[i]);
		}
		else if(opr[i]==9)
		{
			while((d=pop())!=8)
			{
				b[j]=d;
				j++;
			}
		}
		else if(opr[i]==0)
		{
			b[j]=main[i];
			j++;
	
		}
	}
	while(top!=-1)
	{
		b[j]=pop();
		j++;
	}
	//postfix evaluation of parallel b
	j=0;
	for(i=0;i<cp;i++)
	{
		if(opr[i]!=0 && opr[i]!=8 && opr[i]!=9)
		{
			while(priority(s[top])>=priority(opr[i]))
			{
				parb[j]=pop();
				j++;
			}
			push(opr[i]);
		}
		else if(opr[i]==8)
		{
			push(opr[i]);
		}
		else if(opr[i]==9)
		{
			while((d=pop())!=8)
			{
				parb[j]=d;
				j++;
			}
		}
		else if(opr[i]==0)
		{
			parb[j]=opr[i];
			j++;
		}
	}
	while(top!=-1)
	{
		parb[j]=pop();
		j++;
	}
	//////////////////////////////////////////////////////////////////////////////////////
    /*for(i=0;i<cp-cbr;i++)
	{
		cout<<b[i];					//postfix expression		
	}	
	cout<<endl;								
    for(i=0;i<cp-cbr;i++)
	{
		cout<<parb[i];
	}*/						//correctly working with brackets. //postfix is done correctly everytime the while loop is executed
	////////////////////////////////////////////////////////////////////////////////////
	float t,x,y;			//evaluation starts...
	for(i=0;i<cp-cbr;i++)
	{
		if(b[i]==1&&parb[i]==b[i])
		{
			x=epop();
			y=epop();
			t=x+y;
			epush(t);
		}
		else if(b[i]==2&&parb[i]==b[i])
		{
			x=epop();
			y=epop();
			t=(x*y);
			epush(t);
		}
		else if(b[i]==3&&parb[i]==b[i])
		{
			x=epop();
			y=epop();
			t=(y-x);
			epush(t);
		}	
		else if(b[i]==4&&parb[i]==b[i])
		{
			x=epop();
			y=epop();
			t=(y/x);
			epush(t);
		}
		else if(b[i]==5&&parb[i]==b[i])
		{
			int u,v,z;
			u=epop();
			v=epop();
			z=(v%u);
			epush(z);
		}
		else if(b[i]==6&&parb[i]==b[i])
		{
			x=epop();
			y=epop();
			t=pow(y,x);
			epush(t);
		}
		else if(b[i]==7&&parb[i]==b[i])
		{
			x=epop();
			y=epop(); 
			t=pow(x,1/y);
			epush(t);
		}
		else if(b[i]==10&&parb[i]==b[i])
		{
			x=epop();
			t=log(x);
			epush(t);
		}
		else if(b[i]==11&&parb[i]==b[i])
		{
			x=epop();
			t=exp(x);
			epush(t);
		}
		else if(b[i]==12&&parb[i]==b[i])
		{
			x=epop();
			t=sin(x*PI/180);
			epush(t);
		}
		else if(b[i]==13&&parb[i]==b[i])
		{
			x=epop();
			t=cos(x*PI/180);
			epush(t);
		}
		else if(b[i]==14&&parb[i]==b[i])
		{
			x=epop();
			t=tan(x*PI/180);
			epush(t);
		}
		else if(parb[i]==0)
		{
			epush(b[i]);
		}
	}
	float ans;
	ans=epop();
	cop=0;
	return ans;

}
void equation(char e1[max],char e2[max])
{
	char c[max],eqn1[max],eqn2[max];
	char temp[max];
	char varx1[max],vary1[max],constant1[max];
	char varx2[max],vary2[max],constant2[max];
	int i,j=0,k;
	float A1,B1,C1,A2,B2,C2;
	float x,y;
	//cout<<"Enter your first equation: ";
	fflush(stdin);
	strcpy(c,e1);
	//gets(c);
	for(i=0;i<strlen(c);i++)
	{
		if(c[i]!=' ')
		{
			eqn1[j]=c[i];
			j++;
		}
	}
	eqn1[j]='\0';
	c[0]='\0';
	//cout<<"Enter your second equation: ";
	strcpy(c,e2);
	//gets(c);
	j=0;
	for(i=0;i<strlen(c);i++)
	{
		if(c[i]!=' ')
		{
			eqn2[j]=c[i];
			j++;
		}
	}
	eqn2[j]='\0';
	int ctx=0,cty=0,con=0;
	j=0;
	for(i=0;eqn1[i]!='=';i++)
	{
		con++;
		if(eqn1[i]!='x'&&eqn1[i]!='y')
		{
			temp[j]=eqn1[i];
			j++;
			if(eqn1[i]=='+'||eqn1[i]=='-')
			{
				temp[j]='1';
				j++;
				temp[j]='*';
				j++;
			}
		}
		else if(eqn1[i]=='x'||eqn1[i]=='y')
		{
			if(i==0)
			{
				temp[j]='1';
				j++;
				temp[j]='*';
				j++;
			}
			if(temp[j-1]=='*')
			{
				temp[j]='1';
				j++;
			}
			else
			{
				temp[j]='*';
				j++;
				temp[j]='1';
				j++;
			}
			temp[j]='\0';
			if(eqn1[i]=='x')
			{	
				if(ctx==0)										//for first time string must be copied
				{
					strcpy(varx1,temp);
					ctx++;
				}
				else
				{
					strcat(varx1,temp);
				}
				//cout<<varx<<endl;
				temp[0]='\0';
				j=0;
			}
			else
			{
				if(cty==0)
				{
					strcpy(vary1,temp);
					cty++;
				}
				else
				{
					strcat(vary1,temp);
				}
				//cout<<vary<<endl;
				temp[0]='\0';
				j=0;
				cty++;
			}
		}
	}
	if(strlen(vary1)==0)
	{
		strcpy(vary1,"0");
	}
	else if(strlen(varx1)==0)
	{
		strcpy(varx1,"0");
	}
	j=0;
	temp[0]='\0';
	for(i=con+1;i<strlen(eqn1);i++)
	{
		temp[j]=eqn1[i];
		j++;
	}
	temp[j]='\0';
	strcpy(constant1,temp);
	A1=arithmetic(varx1);
	B1=arithmetic(vary1);
	C1=arithmetic(constant1);
	cout<<"A1 : "<<A1<<endl<<"B1 : "<<B1<<endl<<"C1 : "<<C1<<endl;
	/////////////////////////////////
	ctx=0,cty=0,con=0;
	j=0;
	for(i=0;eqn2[i]!='=';i++)
	{
		con++;
		if(eqn2[i]!='x'&&eqn2[i]!='y')
		{
			temp[j]=eqn2[i];
			j++;
			if(eqn2[i]=='+'||eqn2[i]=='-')
			{
				temp[j]='1';
				j++;
				temp[j]='*';
				j++;
			}
		}
		else if(eqn2[i]=='x'||eqn2[i]=='y')
		{
			if(i==0)
			{
				temp[j]='1';
				j++;
				temp[j]='*';
				j++;
			}		
			if(temp[j-1]=='*')
			{
				temp[j]='1';
				j++;
			}
			else
			{
				temp[j]='*';
				j++;
				temp[j]='1';
				j++;
			}
			temp[j]='\0';
			if(eqn2[i]=='x')
			{
				if(ctx==0)
				{
					strcpy(varx2,temp);
					ctx++;
				}
				else
				{
					strcat(varx2,temp);
				}
				//cout<<varx<<endl;
				temp[0]='\0';
				j=0;
			}
			else
			{
				if(cty==0)
				{
					strcpy(vary2,temp);
					cty++;
				}
				else
				{
					strcat(vary2,temp);
				}
				//cout<<vary<<endl;
				temp[0]='\0';
				j=0;
				cty++;
			}
		}
	}
	if(strlen(vary2)==0)
	{
		strcpy(vary2,"0");
	}
	else if(strlen(varx2)==0)
	{
		strcpy(varx2,"0");
	}
	j=0;
	temp[0]='\0';
	for(i=con+1;i<strlen(eqn2);i++)
	{
		temp[j]=eqn2[i];
		j++;
	}
	temp[j]='\0';
	strcpy(constant2,temp);
	A2=arithmetic(varx2);
	B2=arithmetic(vary2);
	C2=arithmetic(constant2);
	cout<<endl<<"A2 : "<<A2<<endl<<"B2 : "<<B2<<endl<<"C2 : "<<C2<<endl;
	/////////////////////////////////////////////////////////it is not working for eqn of type E.G., 2*x=4 and 2*x+3*y=5....it is working for all other eqn.
	x=((C1*B2)-(C2*B1))/((A1*B2)-(A2*B1));
	y=((C1*A2)-(C2*A1))/((B1*A2)-(B2*A1));
	cout<<"value of x is "<<x<<endl;
	cout<<"value of y is "<<y<<endl;
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}
int main()
{
	int ch;
	fstream myfile;
	cout<<endl;
	end_line();
	cout<<endl;
	fflush(stdin);
	design();
	cout<<endl<<"NOTE: "<<endl<<endl<<"1.)Use <nth power>r<value> for nth root function"<<endl<<"2.)Use 'l' for logarithmic function"<<endl<<"3.)Use 'e' for exponential function"<<endl<<"4.)Use 's' for sine function"<<endl<<"5.)Use 'c' for cosine function"<<endl<<"6.)Use 't' for tangent function"<<endl;
	cout<<endl<<"7.)Use variables x and y only"<<endl<<"8.)Constant terms in the equation must be strictly written after '=' (equal to) "<<endl;
	end_line();
	cout<<endl;
	design();
	cout<<endl<<endl;
	while(1)
	{
		end_line();
		cout<<endl;
		design();
		cout<<endl<<"**What do you want solve?**"<<endl<<endl;
		cout<<"1.)arithmetic equation"<<endl<<"2.)polynomial equation"<<endl<<"3.)Solve equation"<<endl<<endl<<"Press 4 for exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>ch;
		end_line();
		cout<<endl;
		design();
		cout<<endl;
		switch(ch)
		{
			case 1:
				float v;
				char input[max];
				//myfile.open("test1.txt", ios::out | ios::in);
				cout<<endl<<"Enter the expression: ";
				fflush(stdin);
				cin>>input;
				//gets(input);
				//myfile<<input;
				//myfile>>input;
				v=arithmetic(input);
				cout<<"Answer: "<<v;
				cout<<endl;
				break;
			case 2:
				poly();
				break;
			case 3:
				char e1[max],e2[max];
				cout<<"Enter first equation: ";
				cin>>e1;
				cout<<"Enter second equation: ";
				cin>>e2;
				equation(e1,e2);
				break;	
			case 4:
				exit(0);
		}
	}
	return 0;
}
