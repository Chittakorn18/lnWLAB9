#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double loan, rate, pay;

    cout << "Enter initial loan: ";
    cin >> loan;

    cout << "Enter interest rate per year (%): ";
    cin >> rate;

    cout << "Enter amount you can pay per year: ";
    cin >> pay;

    cout << setw(13) << left << "EndOfYear#"
         << setw(13) << left << "PrevBalance"
         << setw(13) << left << "Interest"
         << setw(13) << left << "Total"
         << setw(13) << left << "Payment"
         << setw(13) << left << "NewBalance" << endl;

    double prevBalance = loan;

	for(int year = 1; prevBalance > 0;year++) {
        double interest = (rate / 100) * prevBalance;
        double total = prevBalance + interest;
        double actualPayment = min(pay, total);

        cout << setw(13) << left << year
             << fixed << setprecision(2)
             << setw(13) << left << prevBalance
             << setw(13) << left << interest
             << setw(13) << left << total
             << setw(13) << left << actualPayment
             << setw(13) << left << (total - actualPayment) << endl;

        prevBalance = total - actualPayment;
    }

    return 0;
}
