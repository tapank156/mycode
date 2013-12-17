CMsgHndlr CMsgHndlr::m_MsgHndlr;
CMsgHndlr* CMsgHndlr::getMsgHndlr()
{
        return &m_MsgHndlr;
}
CMsgHndlr::CMsgHndlr()
{
        cout << "CMsgHndlr() = " << count << endl;
	emp = new CEmployee();
}
CMsgHndlr::~CMsgHndlr()
{
        cout << "~CMsgHndlr() = " << count << endl;
	delete emp;
}
CEmployee*  CMsgHandlr::getEmployee()
{
	return emp;
}
void CMsgHandlr::setEmployeeParams(int code, string name, int age)
{
	emp = new CEmployee(code, name, age);
}
void CMsgHandlr::setEmployee(CEmployee * ep)
{
	emp = ep; 
}
