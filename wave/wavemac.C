 #include <TMath.h>
void wavemac()
{
  TFile *f = TFile::Open("Fits.root", "READ");
  
  TH1F* myhist = (TH1F*)f->Get("hfs"); 
  //TF1 *mysin= new TF1("mysin", "([0]*sin([1]*x + [2])) + [3]", -40, 40.);
  TF1 *mysimplesin = new TF1("mysimplesin", "(-[0]*sin([1]*x + [2])) + [3]", -40, 40.);
  mysimplesin -> SetParLimits(0,45,100);
  mysimplesin -> SetParLimits(1,0.35,30);
  mysimplesin -> SetParLimits(2,0,10);
  mysimplesin -> SetParLimits(3,0,3);
  //mysimplesin -> FixParameter(2,1.4);

  
  myhist -> Fit("mysimplesin"); 
  myhist->Draw();
  
  
}

