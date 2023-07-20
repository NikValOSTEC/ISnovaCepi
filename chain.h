#pragma once
#include<qobject.h>
#include"qcolor.h"
class Pin;
#ifndef CHAIN_H
#define CHAIN_H
/// <summary>
/// ����� ����
/// <param>
/// �������� ����������� � ���� ��������
/// </param>
/// </summary>
class Chain :public QObject
{
    Q_OBJECT
public:
    /// <summary>
    /// ����� ���� ��� ���������� 2 ��������� ��� �����
    /// <para>
    /// ��� ���� ����� � ����������� ������ chains
    /// </para>
    /// </summary>
    Chain();
    /// <summary>
    /// �����������
    /// </summary>
    ~Chain();
    /// <summary>
    /// ���������� ������� � ���� ��� ���������� ��� � ��������� �������� � ������ ����
    /// </summary>
    /// <param name="p">�������</param>
    void AddPin(Pin* p);
    /// <summary>
    /// ������� ������� �� ����
    /// </summary>
    /// <param name="p">��������� �������</param>
    void RemovePin(Pin* p);
    /// <summary>
    /// ����������� ������ ���������� ��������� �� ��� ���� ��� ��������� ���� ����� �� ���
    /// </summary>
    static QVector<Chain*> chains;
    /// <summary>
    /// �������� �������� � ����
    /// </summary>
    QVector<Pin*> pins;
    /// <summary>
    /// ���������� ������ ���� � chain � ����
    /// </summary>
    /// <param name="chain"></param>
    void moveToChain(Chain* chain); 
    /// <summary>
    /// �������� ���������� >2 ����� �  1 �����, � ����
    /// </summary>
    void Dots();
    /// <summary>
    /// ���� �������� � ����
    /// </summary>
    QColor color;
};
#endif
