#pragma once

#include "wx/wx.h"
#include "cParser.h"

enum BTN_ID : unsigned short
{
    ID_BUTTON_DELALL = 10001,
    ID_BUTTON_DELLAST,
    ID_BUTTON_ZERO,
    ID_BUTTON_ONE,
    ID_BUTTON_TWO,
    ID_BUTTON_THREE,
    ID_BUTTON_FOUR,
    ID_BUTTON_FIVE,
    ID_BUTTON_SIX,
    ID_BUTTON_SEVEN,
    ID_BUTTON_EIGHT,
    ID_BUTTON_NINE,
    ID_BUTTON_POINT,
    ID_BUTTON_ABS,
    ID_BUTTON_ADD,
    ID_BUTTON_DIV,
    ID_BUTTON_EQUALS,
    ID_BUTTON_FACT,
    ID_BUTTON_LEFTBRACKET,
    ID_BUTTON_MOD,
    ID_BUTTON_MUL,
    ID_BUTTON_RIGHTBRACKET,
    ID_BUTTON_CHANGESIGN,
    ID_BUTTON_SQR,
    ID_BUTTON_SQRT,
    ID_BUTTON_SUB,
    ID_BUTTON_DEL,
    ID_TEXTCTRL_INPUT,
    ID_BUTTON_ANGLEMEASURE,
    ID_BUTTON_SIN,
    ID_BUTTON_COS,
    ID_BUTTON_TAN,
    ID_BUTTON_ARCSIN,
    ID_BUTTON_ARCCOS,
    ID_BUTTON_ARCTAN,
    ID_BUTTON_PI
};

class cMain : public wxFrame
{
    public:
        cMain();
        virtual ~cMain();

    public:

        wxButton* m_DelAll = nullptr;
        wxButton* m_DelLast = nullptr;
        wxButton* m_Zero = nullptr;
        wxButton* m_One = nullptr;
        wxButton* m_Two = nullptr;
        wxButton* m_Three = nullptr;
        wxButton* m_Four = nullptr;
        wxButton* m_Five = nullptr;
        wxButton* m_Six = nullptr;
        wxButton* m_Seven = nullptr;
        wxButton* m_Eight = nullptr;
        wxButton* m_Nine = nullptr;
        wxButton* m_Point = nullptr;
        wxButton* m_Abs = nullptr;
        wxButton* m_Add = nullptr;
        wxButton* m_Div = nullptr;
        wxButton* m_Equals = nullptr;
        wxButton* m_Fact = nullptr;
        wxButton* m_LeftBracket = nullptr;
        wxButton* m_Mod = nullptr;
        wxButton* m_Mul = nullptr;
        wxButton* m_RightBracket = nullptr;
        wxButton* m_ChangeSign = nullptr;
        wxButton* m_Pow = nullptr;
        wxButton* m_Sqrt = nullptr;
        wxButton* m_Sub = nullptr;
        wxButton* m_Del = nullptr;
        wxButton* m_AngleMeasure = nullptr;
        wxButton* m_Sin = nullptr;
        wxButton* m_Cos = nullptr;
        wxButton* m_Tan = nullptr;
        wxButton* m_ArcSin = nullptr;
        wxButton* m_ArcCos = nullptr;
        wxButton* m_ArcTan = nullptr;
        wxButton* m_Pi = nullptr;

        wxTextCtrl* m_Input = nullptr;

        void OnQuit(wxCommandEvent& event);

        void OnDelAllClick(wxCommandEvent& evt);
        void OnDelLastClick(wxCommandEvent& evt);
        void OnZeroClick(wxCommandEvent& evt);
        void OnOneClick(wxCommandEvent& evt);
        void OnTwoClick(wxCommandEvent& evt);
        void OnThreeClick(wxCommandEvent& evt);
        void OnFourClick(wxCommandEvent& evt);
        void OnFiveClick(wxCommandEvent& evt);
        void OnSixClick(wxCommandEvent& evt);
        void OnSevenClick(wxCommandEvent& evt);
        void OnEightClick(wxCommandEvent& evt);
        void OnNineClick(wxCommandEvent& evt);
        void OnPointClick(wxCommandEvent& evt);
        void OnAbsClick(wxCommandEvent& evt);
        void OnAddClick(wxCommandEvent& evt);
        void OnDivClick(wxCommandEvent& evt);
        void OnEqualsClick(wxCommandEvent& evt);
        void OnFactClick(wxCommandEvent& evt);
        void OnLeftBracketClick(wxCommandEvent& evt);
        void OnModClick(wxCommandEvent& evt);
        void OnMulClick(wxCommandEvent& evt);
        void OnRightBracketClick(wxCommandEvent& evt);
        void OnChangeSignClick(wxCommandEvent& evt);
        void OnSqrClick(wxCommandEvent& evt);
        void OnSqrtClick(wxCommandEvent& evt);
        void OnSubClick(wxCommandEvent& evt);
        void OnDelClick(wxCommandEvent& evt);
        void OnAngleMeasureClick(wxCommandEvent& evt);
        void OnSinClick(wxCommandEvent& evt);
        void OnCosClick(wxCommandEvent& evt);
        void OnTanClick(wxCommandEvent& evt);
        void OnArcSinClick(wxCommandEvent& evt);
        void OnArcCosClick(wxCommandEvent& evt);
        void OnArcTanClick(wxCommandEvent& evt);
        void OnPiClick(wxCommandEvent& evt);

        cParser* m_Parser = nullptr;
        std::string sExpression = "";
        std::string sLastValue = "";
        bool bRadians = true;

        wxDECLARE_EVENT_TABLE();
};
