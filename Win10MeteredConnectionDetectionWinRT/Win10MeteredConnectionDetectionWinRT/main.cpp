// main.cpp : Defines the entry point for the console application.
//

#pragma comment(lib, "windowsapp")
#include "pch.h"
#include <winrt/Windows.Networking.Connectivity.h>

using namespace winrt;
using namespace winrt::Windows::Networking::Connectivity;

int main()
{
    init_apartment();

	// Retrieve connectivity information
	ConnectionProfile p = NetworkInformation::GetInternetConnectionProfile();
	ConnectionCost c = p.GetConnectionCost();
	NetworkCostType nct = c.NetworkCostType();

	// Output cost type
	if (nct == NetworkCostType::Unrestricted) {
		printf("Unrestricted\n");
	}
	else {
		printf("Not unrestricted\n");
	}
}
