Inventory *Inventory::invInst = 0;

Inventory *Inventory::getInstance()
{
	if (invInst == 0)
	{
		invInst = new Inventory();
	}
	return invInst;
}

Inventory::Inventory()
{
	woodCount = 0;
	foodCount = 0;
	waterCount = 0;
}
