#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
    EVT_BUTTON(ID_BUTTON_CHANGESIGN, cMain::OnChangeSignClick)
    EVT_BUTTON(ID_BUTTON_ZERO, cMain::OnZeroClick)
    EVT_BUTTON(ID_BUTTON_POINT, cMain::OnPointClick)
    EVT_BUTTON(ID_BUTTON_EQUALS, cMain::OnEqualsClick)
    EVT_BUTTON(ID_BUTTON_FIVE, cMain::OnFiveClick)
    EVT_BUTTON(ID_BUTTON_TWO, cMain::OnTwoClick)
    EVT_BUTTON(ID_BUTTON_ONE, cMain::OnOneClick)
    EVT_BUTTON(ID_BUTTON_ADD, cMain::OnAddClick)
    EVT_BUTTON(ID_BUTTON_FOUR, cMain::OnFourClick)
    EVT_BUTTON(ID_BUTTON_SUB, cMain::OnSubClick)
    EVT_BUTTON(ID_BUTTON_SIX, cMain::OnSixClick)
    EVT_BUTTON(ID_BUTTON_THREE, cMain::OnThreeClick)
    EVT_BUTTON(ID_BUTTON_SEVEN, cMain::OnSevenClick)
    EVT_BUTTON(ID_BUTTON_NINE, cMain::OnNineClick)
    EVT_BUTTON(ID_BUTTON_MUL, cMain::OnMulClick)
    EVT_BUTTON(ID_BUTTON_EIGHT, cMain::OnEightClick)
    EVT_BUTTON(ID_BUTTON_SQRT, cMain::OnSqrtClick)
    EVT_BUTTON(ID_BUTTON_SQR, cMain::OnSqrClick)
    EVT_BUTTON(ID_BUTTON_DIV, cMain::OnDivClick)
    EVT_BUTTON(ID_BUTTON_MOD, cMain::OnModClick)
    EVT_BUTTON(ID_BUTTON_DELLAST, cMain::OnDelLastClick)
    EVT_BUTTON(ID_BUTTON_DELALL, cMain::OnDelAllClick)
    EVT_BUTTON(ID_BUTTON_DEL, cMain::OnDelClick)
    EVT_BUTTON(ID_BUTTON_LEFTBRACKET, cMain::OnLeftBracketClick)
    EVT_BUTTON(ID_BUTTON_RIGHTBRACKET, cMain::OnRightBracketClick)
    EVT_BUTTON(ID_BUTTON_ABS, cMain::OnAbsClick)
    EVT_BUTTON(ID_BUTTON_FACT, cMain::OnFactClick)
    EVT_BUTTON(ID_BUTTON_ANGLEMEASURE, cMain::OnAngleMeasureClick)
    EVT_BUTTON(ID_BUTTON_SIN, cMain::OnSinClick)
    EVT_BUTTON(ID_BUTTON_COS, cMain::OnCosClick)
    EVT_BUTTON(ID_BUTTON_TAN, cMain::OnTanClick)
    EVT_BUTTON(ID_BUTTON_ARCSIN, cMain::OnArcSinClick)
    EVT_BUTTON(ID_BUTTON_ARCCOS, cMain::OnArcCosClick)
    EVT_BUTTON(ID_BUTTON_ARCTAN, cMain::OnArcTanClick)
    EVT_BUTTON(ID_BUTTON_PI, cMain::OnPiClick)
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(30, 30), wxSize(385, 500))
{
    SetForegroundColour(wxColour(255, 255, 255));
    SetBackgroundColour(wxColour(255, 255, 255));

    m_Input = new wxTextCtrl(this, ID_TEXTCTRL_INPUT, _("0"), wxPoint(8, 8), wxSize(350, 96), 0, wxDefaultValidator, _T("ID_INPUT"));

    wxFont InputFont(28, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, _T("@Microsoft YaHei"), wxFONTENCODING_DEFAULT);
    m_Input->SetFont(InputFont);

    m_ChangeSign = new wxButton(this, ID_BUTTON_CHANGESIGN, _("+/-"), wxPoint(8, 400), wxSize(64, 39), 0, wxDefaultValidator, _T("ID_BUTTON_CHANGESIGN"));
    m_Zero = new wxButton(this, ID_BUTTON_ZERO, _("0"), wxPoint(80, 400), wxSize(64, 39), 0, wxDefaultValidator, _T("ID_BUTTON_ZERO"));
    m_Point = new wxButton(this, ID_BUTTON_POINT, _("."), wxPoint(152, 400), wxSize(64, 39), 0, wxDefaultValidator, _T("ID_BUTTON_POINT"));
    m_Equals = new wxButton(this, ID_BUTTON_EQUALS, _("="), wxPoint(224, 400), wxSize(64, 39), 0, wxDefaultValidator, _T("ID_BUTTON_EQUALS"));
    m_Five = new wxButton(this, ID_BUTTON_FIVE, _("5"), wxPoint(80, 304), wxSize(64, 39), 0, wxDefaultValidator, _T("ID_BUTTON_FIVE"));
    m_Two = new wxButton(this, ID_BUTTON_TWO, _("2"), wxPoint(80, 352), wxSize(64, 39), 0, wxDefaultValidator, _T("ID_BUTTON_TWO"));
    m_One = new wxButton(this, ID_BUTTON_ONE, _("1"), wxPoint(8, 352), wxSize(64, 39), 0, wxDefaultValidator, _T("ID_BUTTON_ONE"));
    m_Add = new wxButton(this, ID_BUTTON_ADD, _("+"), wxPoint(224, 352), wxSize(64, 39), 0, wxDefaultValidator, _T("ID_BUTTON_ADD"));
    m_Four = new wxButton(this, ID_BUTTON_FOUR, _("4"), wxPoint(8, 304), wxSize(64, 39), 0, wxDefaultValidator, _T("ID_BUTTON_FOUR"));
    m_Sub = new wxButton(this, ID_BUTTON_SUB, _("-"), wxPoint(224, 304), wxSize(64, 39), 0, wxDefaultValidator, _T("ID_BUTTON_SUB"));
    m_Six = new wxButton(this, ID_BUTTON_SIX, _("6"), wxPoint(152, 304), wxSize(64, 39), 0, wxDefaultValidator, _T("ID_BUTTON_SIX"));
    m_Three = new wxButton(this, ID_BUTTON_THREE, _("3"), wxPoint(152, 352), wxSize(64, 39), 0, wxDefaultValidator, _T("ID_BUTTON_THREE"));
    m_Seven = new wxButton(this, ID_BUTTON_SEVEN, _("7"), wxPoint(8, 256), wxSize(64, 39), 0, wxDefaultValidator, _T("ID_BUTTON_SEVEN"));
    m_Nine = new wxButton(this, ID_BUTTON_NINE, _("9"), wxPoint(152, 256), wxSize(64, 39), 0, wxDefaultValidator, _T("ID_BUTTON_NINE"));
    m_Mul = new wxButton(this, ID_BUTTON_MUL, _("*"), wxPoint(224, 256), wxSize(64, 39), 0, wxDefaultValidator, _T("ID_BUTTON_MUL"));
    m_Eight = new wxButton(this, ID_BUTTON_EIGHT, _("8"), wxPoint(80, 256), wxSize(64, 39), 0, wxDefaultValidator, _T("ID_BUTTON_EIGHT"));
    m_Sqrt = new wxButton(this, ID_BUTTON_SQRT, _("sqrt(x)"), wxPoint(152, 208), wxSize(64, 39), 0, wxDefaultValidator, _T("ID_BUTTON_SQRT"));
    m_Pow = new wxButton(this, ID_BUTTON_SQR, _("x^y"), wxPoint(80, 208), wxSize(64, 39), 0, wxDefaultValidator, _T("ID_BUTTON_SQR"));
    m_Div = new wxButton(this, ID_BUTTON_DIV, _("/"), wxPoint(224, 208), wxSize(64, 39), 0, wxDefaultValidator, _T("ID_BUTTON_DIV"));
    m_Mod = new wxButton(this, ID_BUTTON_MOD, _("%"), wxPoint(8, 112), wxSize(64, 39), 0, wxDefaultValidator, _T("ID_BUTTON_MOD"));
    m_DelLast = new wxButton(this, ID_BUTTON_DELLAST, _("CE"), wxPoint(80, 112), wxSize(64, 39), 0, wxDefaultValidator, _T("ID_BUTTON_DELLAST"));
    m_DelAll = new wxButton(this, ID_BUTTON_DELALL, _("C"), wxPoint(152, 112), wxSize(64, 39), 0, wxDefaultValidator, _T("ID_BUTTON_DELALL"));
    m_Del = new wxButton(this, ID_BUTTON_DEL, _("<x"), wxPoint(224, 112), wxSize(64, 39), 0, wxDefaultValidator, _T("ID_BUTTON_DEL"));
    m_LeftBracket = new wxButton(this, ID_BUTTON_LEFTBRACKET, _("("), wxPoint(8, 160), wxSize(64, 39), 0, wxDefaultValidator, _T("ID_BUTTON_LEFTBRACKET"));
    m_RightBracket = new wxButton(this, ID_BUTTON_RIGHTBRACKET, _(")"), wxPoint(80, 160), wxSize(64, 39), 0, wxDefaultValidator, _T("ID_BUTTON_RIGHTBRACKET"));
    m_Abs = new wxButton(this, ID_BUTTON_ABS, _("| x |"), wxPoint(152, 160), wxSize(64, 39), 0, wxDefaultValidator, _T("ID_BUTTON_ABS"));
    m_Fact = new wxButton(this, ID_BUTTON_FACT, _("n!"), wxPoint(224, 160), wxSize(64, 39), 0, wxDefaultValidator, _T("ID_BUTTON_FACT"));
    m_AngleMeasure = new wxButton(this, ID_BUTTON_ANGLEMEASURE, _("rad"), wxPoint(296, 112), wxSize(64, 39), 0, wxDefaultValidator, _T("ID_BUTTON_ANGLEMEASURE"));
    m_Sin = new wxButton(this, ID_BUTTON_SIN, _("sin"), wxPoint(296, 160), wxSize(64, 39), 0, wxDefaultValidator, _T("ID_BUTTON_SIN"));
    m_Cos = new wxButton(this, ID_BUTTON_COS, _("cos"), wxPoint(296, 208), wxSize(64, 39), 0, wxDefaultValidator, _T("ID_BUTTON_COS"));
    m_Tan = new wxButton(this, ID_BUTTON_TAN, _("tan"), wxPoint(296, 256), wxSize(64, 39), 0, wxDefaultValidator, _T("ID_BUTTON_TAN"));
    m_ArcSin = new wxButton(this, ID_BUTTON_ARCSIN, _("asin"), wxPoint(296, 304), wxSize(64, 39), 0, wxDefaultValidator, _T("ID_BUTTON_ARCSIN"));
    m_ArcCos = new wxButton(this, ID_BUTTON_ARCCOS, _("acos"), wxPoint(296, 352), wxSize(64, 39), 0, wxDefaultValidator, _T("ID_BUTTON_ARCCOS"));
    m_ArcTan = new wxButton(this, ID_BUTTON_ARCTAN, _("atan"), wxPoint(296, 400), wxSize(64, 39), 0, wxDefaultValidator, _T("ID_BUTTON_ARCTAN"));
    m_Pi = new wxButton(this, ID_BUTTON_PI, _("pi"), wxPoint(8, 208), wxSize(64, 39), 0, wxDefaultValidator, _T("ID_BUTTON_PI"));

    m_Parser = new cParser;
}

cMain::~cMain()
{
    delete m_Parser;

    delete m_DelAll;
    delete m_DelLast;
    delete m_Zero;
    delete m_One;
    delete m_Two;
    delete m_Three;
    delete m_Four;
    delete m_Five;
    delete m_Six;
    delete m_Seven;
    delete m_Eight;
    delete m_Nine;
    delete m_Point;
    delete m_Abs;
    delete m_Add;
    delete m_Div;
    delete m_Equals;
    delete m_Fact;
    delete m_LeftBracket;
    delete m_Mod;
    delete m_Mul;
    delete m_RightBracket;
    delete m_ChangeSign;
    delete m_Pow;
    delete m_Sqrt;
    delete m_Sub;
    delete m_Del;
    delete m_Input;
}

void cMain::OnQuit(wxCommandEvent& evt)
{
    this->Destroy();
}

void cMain::OnDelAllClick(wxCommandEvent& evt)
{
    m_Input->SetValue(_("0"));
    sExpression = "";
    sLastValue = "";
    evt.Skip();
}

void cMain::OnDelLastClick(wxCommandEvent& evt)
{
    m_Input->SetValue(_("0"));

    if (sLastValue.length() != 0)
        sLastValue.pop_back();
    else if (sExpression.length() != 0)
        sExpression.pop_back();

    evt.Skip();
}

void cMain::OnZeroClick(wxCommandEvent& evt)
{
    sLastValue += "0";
    m_Input->SetValue(_(sExpression + sLastValue));
    evt.Skip();
}

void cMain::OnOneClick(wxCommandEvent& evt)
{
    sLastValue += "1";
    m_Input->SetValue(_(sExpression + sLastValue));
    evt.Skip();
}

void cMain::OnTwoClick(wxCommandEvent& evt)
{
    sLastValue += "2";
    m_Input->SetValue(_(sExpression + sLastValue));
    evt.Skip();
}

void cMain::OnThreeClick(wxCommandEvent& evt)
{
    sLastValue += "3";
    m_Input->SetValue(_(sExpression + sLastValue));
    evt.Skip();
}

void cMain::OnFourClick(wxCommandEvent& evt)
{
    sLastValue += "4";
    m_Input->SetValue(_(sExpression + sLastValue));
    evt.Skip();
}

void cMain::OnFiveClick(wxCommandEvent& evt)
{
    sLastValue += "5";
    m_Input->SetValue(_(sExpression + sLastValue));
    evt.Skip();
}

void cMain::OnSixClick(wxCommandEvent& evt)
{
    sLastValue += "6";
    m_Input->SetValue(_(sExpression + sLastValue));
    evt.Skip();
}

void cMain::OnSevenClick(wxCommandEvent& evt)
{
    sLastValue += "7";
    m_Input->SetValue(_(sExpression + sLastValue));
    evt.Skip();
}

void cMain::OnEightClick(wxCommandEvent& evt)
{
    sLastValue += "8";
    m_Input->SetValue(_(sExpression + sLastValue));
    evt.Skip();
}

void cMain::OnNineClick(wxCommandEvent& evt)
{
    sLastValue += "9";
    m_Input->SetValue(_(sExpression + sLastValue));
    evt.Skip();
}

void cMain::OnPointClick(wxCommandEvent& evt)
{
    sLastValue += ".";
    m_Input->SetValue(_(sExpression + sLastValue));
    evt.Skip();
}

void cMain::OnAbsClick(wxCommandEvent& evt)
{
    sLastValue += "abs";
    m_Input->SetValue(_(sExpression + sLastValue));
    evt.Skip();
}

void cMain::OnAddClick(wxCommandEvent& evt)
{
    sExpression += sLastValue + "+";
    sLastValue = "";
    m_Input->SetValue(_(sExpression + sLastValue));
    evt.Skip();
}

void cMain::OnDivClick(wxCommandEvent& evt)
{
    sExpression += sLastValue + "/";
    sLastValue = "";
    m_Input->SetValue(_(sExpression + sLastValue));
    evt.Skip();
}

void cMain::OnEqualsClick(wxCommandEvent& evt)
{
    sExpression += sLastValue;
    sLastValue = "";
    
    std::string sResult = std::to_string(m_Parser->Get((char*)sExpression.c_str(), bRadians));
    sExpression = "";

    m_Input->SetValue(_(sResult.c_str()));

    sExpression = sResult;

    evt.Skip();

}

void cMain::OnFactClick(wxCommandEvent& evt)
{
    sExpression += "!";
    m_Input->SetValue(_(sExpression + sLastValue));
    evt.Skip();
}

void cMain::OnLeftBracketClick(wxCommandEvent& evt)
{
    sLastValue += "(";
    m_Input->SetValue(_(sExpression + sLastValue));

    evt.Skip();
}

void cMain::OnModClick(wxCommandEvent& evt)
{
    sExpression += sLastValue + "%";
    sLastValue = "";
    m_Input->SetValue(_(sExpression + sLastValue));

    evt.Skip();
}

void cMain::OnMulClick(wxCommandEvent& evt)
{
    sExpression += sLastValue + "*";
    sLastValue = "";
    m_Input->SetValue(_(sExpression + sLastValue));

    evt.Skip();
}

void cMain::OnRightBracketClick(wxCommandEvent& evt)
{
    sLastValue += ")";
    m_Input->SetValue(_(sExpression + sLastValue));

    evt.Skip();
}

void cMain::OnChangeSignClick(wxCommandEvent& evt)
{
    if (sLastValue[0] == '-')
        sLastValue.erase(0, 1);
    else
        sLastValue = '-' + sLastValue;

    m_Input->SetValue(_(sExpression + sLastValue));

    evt.Skip();
}

void cMain::OnSqrClick(wxCommandEvent& evt)
{
    sLastValue += "^";
    m_Input->SetValue(_(sExpression + sLastValue));

    evt.Skip();
}

void cMain::OnSqrtClick(wxCommandEvent& evt)
{
    sLastValue += "sqrt";
    m_Input->SetValue(_(sExpression + sLastValue));

    evt.Skip();
}

void cMain::OnSubClick(wxCommandEvent& evt)
{
    sExpression += sLastValue + "-";
    sLastValue = "";
    m_Input->SetValue(_(sExpression + sLastValue));

    evt.Skip();
}

void cMain::OnDelClick(wxCommandEvent& evt)
{
    if (sLastValue.length() != 0)
        sLastValue.pop_back();
    else if (sExpression.length() != 0)
        sExpression.pop_back();
    
    m_Input->SetValue(_(((sExpression + sLastValue).length() == 0) ? "0" : sExpression + sLastValue));

    evt.Skip();
}

void cMain::OnAngleMeasureClick(wxCommandEvent& evt)
{
    bRadians = !bRadians;

    if (bRadians)
        m_AngleMeasure->SetLabelText("rad");
    else
        m_AngleMeasure->SetLabelText("deg");
}

void cMain::OnSinClick(wxCommandEvent& evt)
{
    sLastValue += "sin";
    m_Input->SetValue(_(sExpression + sLastValue));

    evt.Skip();
}

void cMain::OnCosClick(wxCommandEvent& evt)
{
    sLastValue += "cos";
    m_Input->SetValue(_(sExpression + sLastValue));

    evt.Skip();
}

void cMain::OnTanClick(wxCommandEvent& evt)
{
    sLastValue += "tan";
    m_Input->SetValue(_(sExpression + sLastValue));

    evt.Skip();
}

void cMain::OnArcSinClick(wxCommandEvent& evt)
{
    sLastValue += "asin";
    m_Input->SetValue(_(sExpression + sLastValue));

    evt.Skip();
}

void cMain::OnArcCosClick(wxCommandEvent& evt)
{
    sLastValue += "acos";
    m_Input->SetValue(_(sExpression + sLastValue));

    evt.Skip();
}

void cMain::OnArcTanClick(wxCommandEvent& evt)
{
    sLastValue += "atan";
    m_Input->SetValue(_(sExpression + sLastValue));

    evt.Skip();
}

void cMain::OnPiClick(wxCommandEvent& evt)
{
    sLastValue += "pi";
    m_Input->SetValue(_(sExpression + sLastValue));

    evt.Skip();
}
