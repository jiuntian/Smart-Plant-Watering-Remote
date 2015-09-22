//pot 11.5 ;18
module pot() {
    cylinder(d1=115,d2=180,h=110,$fn=200);
}
module boxout(){
    
difference(){
translate([-50,-120,10])
cube([100,65,70] );
pot();}}


module boxcase(){
difference(){
boxout();
translate([0,-10,5])
scale([.9,1,.9])
boxout();
}}


difference(){
boxcase();
    
translate([-51,-100,60])
rotate([0,90,0])
cylinder(d=3,h=7,$fn=20);

translate([-51,-100,24])
rotate([0,90,0])
cylinder(d=3,h=7,$fn=20);
    
translate([-51,-111,42])
rotate([0,90,0])
cylinder(d=12,h=7,$fn=40);

translate([-51,-85,18])
rotate([0,90,0])
cylinder(d=4,h=7,$fn=20);
    
translate([44,-111,42])
rotate([0,90,0])
cylinder(d=12,h=7,$fn=40);
//screw1
translate([-47.5,-122,20])
rotate([0,90,90])
cylinder(d=2.95,h=7,$fn=20);
//screw2
translate([-47.5,-122,70])
rotate([0,90,90])
cylinder(d=2.95,h=7,$fn=20);
//distance in Z , 50mm
//distance in X , 95mm
//screw3
translate([47.5,-122,20])
rotate([0,90,90])
cylinder(d=2.95,h=7,$fn=20);
//screw4
translate([47.5,-122,70])
rotate([0,90,90])
cylinder(d=2.95,h=7,$fn=20);
}
