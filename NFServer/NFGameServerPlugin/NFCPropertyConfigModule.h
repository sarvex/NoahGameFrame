// -------------------------------------------------------------------------
//    @FileName      :    NFCPropertyConfigModule.h
//    @Author           :    LvSheng.Huang
//    @Date             :    2013-09-30
//    @Module           :    NFCPropertyConfigModule
//
// -------------------------------------------------------------------------

#ifndef _NFC_PROPERTY_CONFIG_MODULE_H_
#define _NFC_PROPERTY_CONFIG_MODULE_H_

#include "NFComm/Config/NFConfig.h"
#include "NFComm/RapidXML/rapidxml.hpp"
#include "NFComm/RapidXML/rapidxml_iterators.hpp"
#include "NFComm/RapidXML/rapidxml_print.hpp"
#include "NFComm/RapidXML/rapidxml_utils.hpp"
#include "NFComm/NFPluginModule/NFIPropertyConfigModule.h"
#include "NFComm/NFPluginModule/NFILogicClassModule.h"
#include "NFComm/NFPluginModule/NFIElementInfoModule.h"

class NFCPropertyConfigModule
    : public NFIPropertyConfigModule
{
public:
    NFCPropertyConfigModule( NFIPluginManager* p )
    {
        pPluginManager = p;
    }
    virtual ~NFCPropertyConfigModule() {};

    virtual bool Init();
    virtual bool Shut();
    virtual bool Execute( const float fLasFrametime, const float fStartedTime );
    virtual bool AfterInit();

    //基础值=等级+系数+常数
    //virtual int CalculateBaseValue(const NFJobType nJob, const int nLevel, NFRumTimeColIndex eProperty);
    virtual int CalculateBaseValue( const NFJobType nJob, const int nLevel, const std::string& strProperty );

    virtual bool NeedView(const std::string& strProperty);

protected:
    void Load();
    void InitViewPropertyList();
private:
    //等级->EffectData
    NFMap<int, std::string> mhtCoefficienData[( int )NFJobType::NJT_MAX];

    NFList<std::string> mViewPropertyList; // 客户端查看角色属性表

    NFILogicClassModule* m_pLogicClassModule;
    NFIElementInfoModule* m_pElementInfoModule;
};


#endif
