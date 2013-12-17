class CMsgHndlr
{
	CEmployee *emp;
        static int count;
public :
	CEmployee*  getEmployee();
	void  setEmployee(CEmployee *ep);
	void  setEmployeeParams(int code, string name, int age);
	static CMsgHndlr * getMsgHndlr();
        virtual ~CMsgHndlr();
protected:
        CMsgHndlr();
        static CMsgHndlr m_MsgHndlr;
};

