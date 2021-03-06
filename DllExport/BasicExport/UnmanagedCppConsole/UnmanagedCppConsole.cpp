// This code is part of example that was prepared specially for https://github.com/3F/Examples
// Copyright (c) 2018  Denis Kuzmin < entry.reg@gmail.com > :: github.com/3F
// Distributed under the MIT License

#include "pch.h"
#include "PEModule.h"
#include "AlgVB.h"
#include "LibraryException.h"

using namespace std;
using namespace examples::dllexport::basicExport;

int main()
{
    cout << ".NET DllExport Examples for Unmanaged Native C++" << endl;
    cout << "https://github.com/3F/Examples" << endl;
    cout << "= = = - = = =" << endl << endl;

    try
    {
        PEModule lib(_T("ClassLibrary1.dll"));
        cout << ".NET ClassLibrary1.dll is ready for requests:\n\n";
        

        /* In the manner of Conari syntax: https://github.com/3F/Conari */

        double x1 = lib.call<double, int, double, double>("AmazingSin", 5, 0, 0);
        printf_s("  AmazingSin(5, 0, 0) == %e\n", x1);

        printf_s(
            "    Is NaN(AmazingSin(5, 0, 0)): %s\n",
            (_isnan(x1) || !_finite(x1)) ? "yes" : "no"
        );

        double x2 = lib.call<double>("AmazingSin", 5, 24.781, (double)11);
        printf_s("  AmazingSin(5, 24.781, 11) == %e\n", x2);
        
        printf_s(
            "    Is NaN(AmazingSin(5, 24.781, 11)): %s\n", 
            (_isnan(x2) || !_finite(x2)) ? "yes" : "no"
        );

        
        cout << endl;


        /* Full wrapping of ClassLibrary2.dll */

        AlgVB vb(_T("ClassLibrary2.dll"));
        cout << "AlgVB wrapper of .NET ClassLibrary2.dll is ready:\n\n";

        double x = vb.superPow(2, 3);
        printf_s("  AlgVB.superPow(2, 3) == %e\n", x);

    }
    catch(LibraryException ex) {
        printf_s("Error: [ %d ] %s\n", ex.getError(), ex.what());
    }

    return 0;
}
