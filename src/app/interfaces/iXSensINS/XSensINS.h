/************************************************************/
/*    FILE: XSensINS.h
/*    ORGN: ENSTA Bretagne Robotics - moos-ivp-enstabretagne
/*    AUTH: 
/*    DATE: 2015
/************************************************************/

#ifndef XSensINS_HEADER
#define XSensINS_HEADER

#include "MOOS/libMOOS/Thirdparty/AppCasting/AppCastingMOOSApp.h"

#include <xsens/xsportinfoarray.h>
#include <xsens/xsdatapacket.h>
#include <xsens/xstime.h>
#include <xcommunication/legacydatapacket.h>
#include <xcommunication/int_xsdatapacket.h>
#include <xcommunication/enumerateusbdevices.h>

#include "deviceclass.h"

class XSensINS : public AppCastingMOOSApp
{
  public:
    XSensINS();
    ~XSensINS();

  protected: // Standard MOOSApp functions to overload  
    bool OnNewMail(MOOSMSG_LIST &NewMail);
    bool Iterate();
    bool OnConnectToServer();
    bool OnStartUp();

  protected: // Standard AppCastingMOOSApp functions to overload 
    bool buildReport();
    void registerVariables();

  protected: // XSensINS functions

  private: // Configuration variables
    DeviceClass m_device;
    std::string m_uart_port;
    int m_uart_baud_rate;

  private: // State variables
    double m_nav_heading;
    double m_velocity_norm;

    XsEuler m_euler;
    XsVector m_acceleration;
    XsVector m_gyro;
    XsVector m_mag;
    XsVector m_latlon;
    XsVector m_velocity;
};

#endif 
