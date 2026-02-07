// stock00.cpp -- implementing the Stock class
// version 00
#include <iostream>
#include "stock00.h"

void Stock::acquire(const std::string & co, long n, double pr)
{
    company = co;
    if (n < 0)
    {
        std::cout << "Number of shares can't be negative; "
                  << company << " shares set to 0.\n";
        shares = 0;
    }
    else
        shares = n;
    share_val = pr;
    set_tot();
}

void Stock::buy(long num, double price)
{
     if (num < 0)
    {
        std::cout << "Number of shares purchased can't be negative. "
             << "Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    using std::cout;
    if (num < 0)
    {
        cout << "Number of shares sold can't be negative. "
             << "Transaction is aborted.\n";
    }
    else if (num > shares)
    {
        cout << "You can't sell more than you have! "
             << "Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

void Stock::show()
{
    std::cout << "Company: " << company
              << "  Shares: " << shares << '\n'
              << "  Share Price: $" << share_val
              << "  Total Worth: $" << total_val << '\n';
}

/* 메인문 */
int main()
{	// 1. 객체 생성(기본 생성자 혹은 초기화)
	Stock sally;

	std::cout <<"---초기 상태 ---" << std::endl;
	sally.acquire("NanoSmart", 20, 12.50); // 초기 데이터 설정
	sally.show();

	// 2. 주식 추가 매수 (buy)
	std::cout << "\n---15주 추가 매수(가격 $18.12)---" << std::endl;
	sally.buy(15, 18.12);
	sally.show();

	// 3. 주식 매도(sell)
	std::cout << "\n---40주 매도 시도(보유량보다 많음)---" <<std::endl;
	sally.sell(40, 20.00); // 방어적 코드 확인
	sally.show();

	//4. 가격 갱신(update)
	std::cout << "\n---주가 급등! ($40.00으로 갱신)---" << std::endl;
	sally.update(40.00);
	sally.show();

	return 0;
}