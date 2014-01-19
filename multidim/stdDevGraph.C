
//#include "TGraphErrors.h"
 
void stdDevGraph()
{
TGraphErrors *h1 = new TGraphErrors("/home/cnm08/workspace/multidim/standarddev.txt", "\%lg \%lg"); 
h1->SetMarkerStyle(20);
h1->SetMarkerSize(1.0); 
h1->GetXaxis()->SetTitle(" Number of samples ");
h1->GetYaxis()->SetTitle(" Standard dev");
h1->Draw("AP");
h1->SetMinimum(0.1);
TF1 *fitfun=new TF1("fitfun", "[0]/(sqrt(x))", 0.,100000.);


h1->Draw("AP");
//bwdis->Draw("Same");
h1->Fit("fitfun");
//c1 -> Update();


}
