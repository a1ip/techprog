// ��������� �������, ��-330801
// ������������ ������ �6. ������
// ������� - 5
/*
������ ������, ��������� �� ��������. ������� ������������ � �����. 
����� ���� �� ����� ����������  ��-��� ��� ����������� ���������. 
� ����� ������ �������� �����. ����� �������� �� ����� 255 ��������. 
��������� ���� ������, ��������� ������� Gets(s) � ��������� ������ 
� ������������ �� ����� ���������.

5. 	���������� ��� �����, ������� ��������� � �� ������ ������.
*/

#include <iostream>
#include <stdio.h> //��� gets()
#include <iomanip> //��� setw()
#include <locale>  //��� ���������
#include <string>  //��� ������ �� ��������

using namespace std;

#define BUF_SIZE 256

int wordCount(char* sentence);

char** wordList(char* sentence, int itemsNum);

int wordEntry(char** list, char* word, int itemsNum);

int main()
{
	setlocale(LC_ALL,"Russian");

	cout << "������������ ������ 6: ������" << endl;
	cout << "----------------------------------------------" << endl;

	//�������� �����������:
	char* paragraph = "���-�� �� ������� �����; ������ �����, ��� ���-�� ���� ���������� ����� ���������; �� � �� �� ���������� ���-�� �������.";

	cout << "�� �����: " << paragraph << endl;
	cout << "----------------------------------------------" << endl;

	//������� ���������� ����:
	int words = wordCount(paragraph);

	//����������� ������ ����:
	char** list = wordList(paragraph, words);

	//����� ���������� ���� ������ � ������ ������ �� ����:
	int entries = wordEntry(list, list[0], words);

	cout << "����� ����, ����������� � ������ ������ ������: " << entries << endl;

	return 0;
}

/*
������������ ����� ���� � �����������
*/
int wordCount(char* sentence)
{
	int count = 0;	//������� ����
	
	//���� �� ����� �����������:
	int i = 0;	//������� �����
	do 
	{	
		//������� �������� ����� �����:
		if ((sentence[i+1] == ' ' && (sentence[i] != '.') && (sentence[i] != ' ')) || (sentence[i+1] == '.' && (sentence[i] != '.') && (sentence[i] != ' ')))
		{
			count++;
		}
		i++;

	} while (sentence[i] != '.' && sentence[i+1] != '\0' );

	return count;
}

/*
��������� ������ ���� �� ������ ����������
*/
char** wordList(char* sentence, int itemsNum)
{
	char** list;	//������ �����������

	list = new char* [itemsNum];	//�������� ������ ��� ��� ������
	
	//���� �� ����� �����������:
	int i = 0;		//������� �����
	int count = 0;	//������� ����
	char* buf = new char [BUF_SIZE];	//�������� ����� ��� �����
	do 
	{		
		//���� ����� ��������:
		if (sentence[i] != ' ' && sentence[i] != '.')
		{	
			int j = i;	//��������� ������� ������ �����
			//���� �� ������ �����:
			do 
			{
				buf[j-i] = sentence[j];	//��������� ����� �����������
				j++;					//������� �������
			} while (sentence[j] != ' ' && sentence[j] != '.');

			buf[j - i] = 0;				//j-i - ��������� ������� � �����
			list[count] = new char [j - i + 1];	//�������� ������ ��� ����� � ������: 
												//j-i+1 - ����� ����� � ������ ������������� ����
			strcpy(list[count++], buf);	//�������� �� ������ � ������

			i = j;	//"�����������" ������� �� ��������� ��������� ������ �����
		}
		i++;
	} while (sentence[i] != '.' && sentence[i+1] != '\0' );

	//������� ��������� �� ������
	return list;
}

/*
������������ ���������� ���������� ����� � ������
*/
int wordEntry(char** list, char* word, int itemsNum)
{
	int entryCount = 0;	//������� ���������� ����������

	//���� �� ����� ������:
	for (int i = 0; i < itemsNum; i++)
	{
		//���� ����� �����
		if (!strcmp(list[i], word))
		{
			entryCount++;	//��������� �������
		}
	}

	return entryCount;
}