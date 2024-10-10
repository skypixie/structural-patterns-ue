// Fill out your copyright notice in the Description page of Project Settings.


#include "Proxy/CSVTable_Proxy.h"
#include "Proxy/CSVTable.h"


/*
* В моем примере заместитель csv таблицы
* делает необходимые проверки, чтобы
* не засорять клиентский код.
*/


/*
* Также данный паттерн можент пригодиться,
* когда игрок может управлять какими-то вспомогательными объектами,
* например вспомогательной турелью, дистанционно.
* Тогда игрок будет отправлять команды, типа выпустить ракету по какому-то актору,
* а прокси-класс будет проверять, находится ли актор в зоне досягаемости объекта,
* или использует ли противник особую маскировку против турелей,
* или действительно ли он является противником, а не союзником и тп.
*/


bool UCSVTable_Proxy::OpenFile(FString FileName)
{
    // check if file exists and etc.
    if (!Table)
    {
        Table = NewObject<UCSVTable>();
        if (IsValid(Table))
        {
            return Table->OpenFile(FileName);
        }
    }
    return false;
}

// if If == -1 then it will add data to the end of the file
bool UCSVTable_Proxy::WriteString(int Id, FString Data)
{
    // check if id exists in file else return false
    Table->WriteString(Id, Data);
    return true;
}
