/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
Full Name  : Tejasvi Nitinkumar Parmar
Section    : ZDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/


// ----------------------------------------------------------------------------
// defines/macros

# define MAXIMUM_PRODUCTS 3
# define CONVERSION_FACTOR 2.20462
# define SERVINGS_GRAMS 64

// ----------------------------------------------------------------------------
// structures

struct CatFoodInfo
{
    int skuNumber;
    double productPrice;
    int calories;
    double poundsWeight;
};

struct ReportData
{
    int skuNum;
    double prices;
    int serveCalorie;
    double lbsWgt;
    double kgWgt;
    int gramsWgt;
    double servingTotal;
    double servingCost;
    double servingCostCalorie;
};

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* numPositive);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* numPositive);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int product);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int numProduct);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double* Price, const int calories, const double* weight);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* pounds, double* equalKg);

// 9. convert lbs: g
int convertLbsG(const double* pounds, int* equalG);

// 10. convert lbs: kg / g
void convertLbs(const double* pounds, double* equalKg, int* equalG);

// 11. calculate: servings based on gPerServ
double calculateServings(const int servingSize, const int totalGrams, double* serveResult);

// 12. calculate: cost per serving
double calculateCostPerServing(const double* price, const double* totalServing, double* costOfServing);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* price, const double* totalCalorie, double* costOfCalorie);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo catFood);


// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData reportInfo, const int cheapProduct);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo catFood);

// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start(void);
