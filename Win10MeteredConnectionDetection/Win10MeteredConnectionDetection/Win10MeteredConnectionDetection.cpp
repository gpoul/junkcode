// Win10MeteredConnectionDetection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include <Windows.Foundation.h>
#include <wrl\wrappers\corewrappers.h>
#include <wrl\client.h>
#include <stdio.h>

using namespace ABI::Windows::Foundation;
using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;

int main()
{
	using namespace Windows::Networking::Connectivity;

	// Initialize the Windows Runtime.
	RoInitializeWrapper initialize(RO_INIT_MULTITHREADED);
	if (FAILED(initialize))
	{
		//return PrintError(__LINE__, initialize);
	}

	// Retrieve connectivity information
	ConnectionProfile^ p = NetworkInformation::GetInternetConnectionProfile();
	ConnectionCost^ c = p->GetConnectionCost();
	NetworkCostType nct = c->NetworkCostType;

	// Output cost type
	if (nct == NetworkCostType::Unrestricted) {
		std::cout << "Unrestricted\n";
	}
	else {
		std::cout << "Not unrestricted\n";
	}
}
