#include <iostream>

enum MonthOfYear
{
 January, 
 February, 
 March, 
 April, 
 May, 
 June,
 July,
 August,
 September,
 October,
 November, 
 December,
};

MonthOfYear operator++(MonthOfYear& month)
{
 if (month == December)
 {
    month = January;
 }
 else
 {
   month = (MonthOfYear) (month + 1);
 }
  return month;
}

MonthOfYear operator++(MonthOfYear& month, int)
{
  MonthOfYear oldMonth = month;
  operator++(month);
  return oldMonth;
}

const char* getName(MonthOfYear month)
{
  switch (month)
  {
  case January:
    return "Січень";
    break;

  case February:
    return "Лютий";
    break;

  case March:
    return "Березень";
    break;

  case April:
    return "Квітень";
    break;

  case May:
    return "Травень";
    break;

  case June:
    return "Червень";
    break;

  case July:
    return "Липень";
    break;

  case August:
    return "Серпень";
    break;

  case September:
    return "Вересень";
    break;

  case October:
    return "Жовтень";
    break;

  case November:
    return "Листопад";
    break;

  default:

    return "Грудень";
    break;
  }
}

int main()
{
for (MonthOfYear m = January; m != December; m++)
    {
        std::cout << getName(m) << std::endl;
    }
    return 0;
}
