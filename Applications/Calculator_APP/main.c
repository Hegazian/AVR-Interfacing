/*
 * main.c
 *
 *  Created on: Dec 22, 2021
 *      Author: aaa
 */



#define F_CPU	8000000UL
#include"avr/delay.h"
#include"LIB/Types.h"
#include"DIO.h"
#include"KPD.h"
#include"LCD.h"
#include"KPD_config.h"

int integer(char arr[]);
f32 Calculate(char cal[]);

void main(void)
{
	u8 i = 0;
	u8 key = 0;
	u8 EqualFlage = 0;
	u8 cal[40];
	//KPD Initialization
	SetPortMode(KPD_PORT,0x0F);
	SetPortValue(KPD_PORT,0xF0);
	//LCD Initialization
	SetPortMode(Data_Port,OUTPUT);
	SetPortMode(Control_Port,OUTPUT);
	LCD_Init();
	//LCD_Write_Cmd(Set_Cursor);

	while(1)
	{
		while(i<40 && EqualFlage == 0)
		{
			key = GetPressedKey();
			cal[i] = key;
			if(key != 0)
			{
				LCD_Write_Char(key);
				if(cal[i] == '=')
				{
					EqualFlage = 1;
					LCD_GoTo_XY(2,1);
					//LCD_Print_Int(-666);
					LCD_Print_Int(Calculate(cal));
				}
				if(cal[i] == 'c')
				{
					for(int j = 0;j<20;j++)
						cal[j]='0';
					i = 0;
					LCD_Clear_Screen();
				}

				i++;
				if(i>=16)
					LCD_Display_Shift(LEFT);
			}

		}
		key = GetPressedKey();
		if(key =='c')
		{
			EqualFlage = 0;
			i = 0;
			LCD_Clear_Screen();
		}

	}

}


f32 Calculate(char cal[])
{
	int i = 0;
	char op1[20];
	char op2[20];
	char operation = 0;
	//char cal[40]={'3','.','4','/','8'};
	float totalresult = 0;
	for(i=0;i<40;i++)
	{
		if(i == 0)
			op1[i] = cal[i];
		else if(cal[i] != '+' && cal[i] != '-' && cal[i] != '*' && cal[i] != '/')
			op1[i] = cal[i];
		else
		{
			operation = cal[i];
			for(int j=0;j<20;j++)
				op2[j] = cal[++i];
			break;
		}
	}

	float operator_1 = integer(op1);
	float operator_2 = integer(op2);
		//printf("%f\t%f\n",operator_1,operator_2);
	switch(operation)
	{
		case '+':totalresult=operator_1+operator_2;break;
		case '-':totalresult=operator_1-operator_2;break;
		case '*':totalresult=operator_1*operator_2;break;
		case '/':totalresult=operator_1/operator_2;break;
	}
	//printf("%.1f",totalresult);

	return totalresult;
}

int integer(char arr[])
{
	int ones=0;
	int donze=0;
	int thouzands =0;
	float result =0;
	if(arr[0] == '-' || arr[0] == '+')
	{
		switch(arr[1])
		{
		case '0': ones =0;break;
		case '1': ones =1;break;
		case '2': ones =2;break;
		case '3': ones =3;break;
		case '4': ones =4;break;
		case '5': ones =5;break;
		case '6': ones =6;break;
		case '7': ones =7;break;
		case '8': ones =8;break;
		case '9': ones =9;break;
		case '-':
		default: ones = 111;break;
		}
		switch(arr[2])
		{
		case '0': donze =2;break;
		case '1': donze =1;break;
		case '2': donze =2;break;
		case '3': donze =3;break;
		case '4': donze =4;break;
		case '5': donze =5;break;
		case '6': donze =6;break;
		case '7': donze =7;break;
		case '8': donze =8;break;
		case '9': donze =9;break;
		default: donze = 111;break;
	}
	switch(arr[3])
	{
		case '0': thouzands =0;break;
		case '1': thouzands =1;break;
		case '2': thouzands =2;break;
		case '3': thouzands =3;break;
		case '4': thouzands =4;break;
		case '5': thouzands =5;break;
		case '6': thouzands =6;break;
		case '7': thouzands =7;break;
		case '8': thouzands =8;break;
		case '9': thouzands =9;break;
		default: thouzands = 111;break;
	}

	if(donze == 111 && thouzands == 111 && arr[0] == '-')
		result = (-1)*ones;
	else if(donze == 111 && thouzands == 111 && arr[0] == '+')
		result = ones;
	else if(ones == 111 && thouzands == 111 && arr[0] == '-')
		result = (-1)*donze;
	else if(ones == 111 && thouzands == 111 && arr[0] == '+')
		result = donze;
	else if(ones == 111 && donze == 111 && arr[0] == '-')
		result = (-1)*thouzands;
	else if(ones == 111 && donze == 111 && arr[0] == '+')
		result = thouzands;
	else if(ones == 111 && arr[0] == '-')
		result = (-1)*(donze*10 + thouzands);
	else if(ones == 111 && arr[0] == '+')
		result = donze*10 + thouzands;
	else if(donze == 111 && arr[0] == '-')
		result = (-1)*(ones*10 + thouzands);
	else if(donze == 111 && arr[0] == '+')
		result = ones*10 + thouzands;
	else if( thouzands == 111 && arr[0] == '-')
		result = (-1)*(ones*10 + donze);
	else if (thouzands == 111 && arr[0] == '+')
		result = ones*10 + donze;
	else if(arr[0] == '-')
		result = (-1)*(ones*100 + donze*10 + thouzands);
	else
		result = ones*100 + donze*10 + thouzands;// +((float)fraction/10);
	return result;
	}
	else
	{
		switch(arr[0])
		{
			case '0': ones =0;break;
			case '1': ones =1;break;
			case '2': ones =2;break;
			case '3': ones =3;break;
			case '4': ones =4;break;
			case '5': ones =5;break;
			case '6': ones =6;break;
			case '7': ones =7;break;
			case '8': ones =8;break;
			case '9': ones =9;break;
			case '-':
			default: ones = 111;break;
		}
		switch(arr[1])
		{
			case '0': donze =2;break;
			case '1': donze =1;break;
			case '2': donze =2;break;
			case '3': donze =3;break;
			case '4': donze =4;break;
			case '5': donze =5;break;
			case '6': donze =6;break;
			case '7': donze =7;break;
			case '8': donze =8;break;
			case '9': donze =9;break;
			default: donze = 111;break;
		}
		switch(arr[2])
		{
			case '0': thouzands =0;break;
			case '1': thouzands =1;break;
			case '2': thouzands =2;break;
			case '3': thouzands =3;break;
			case '4': thouzands =4;break;
			case '5': thouzands =5;break;
			case '6': thouzands =6;break;
			case '7': thouzands =7;break;
			case '8': thouzands =8;break;
			case '9': thouzands =9;break;
			default: thouzands = 111;break;
		}

		if(donze == 111 && thouzands == 111)
			result = ones;
		else if(ones == 111 && thouzands == 111)
			result = donze;
		else if(ones == 111 && donze == 111)
			result = thouzands;
		else if(ones == 111)
			result = donze*10 + thouzands;
		else if(donze == 111)
			result = ones*10 + thouzands;
		else if (thouzands == 111)
			result = ones*10 + donze;
		else
			result = ones*100 + donze*10 + thouzands;// +((float)fraction/10);
		return result;
	}
}
