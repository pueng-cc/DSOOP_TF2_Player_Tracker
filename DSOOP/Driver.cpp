#include <stdio.h>
#include <stdlib.h>
#include "UI.h"
#include "Container.h"

int main()
{
	Container *playerContainer = new Container;
	UI theUI(playerContainer);
	theUI.UIDriver();
	return 0;
}