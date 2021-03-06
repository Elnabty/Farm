function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "App_v0p1"};
	this.sidHashMap["App_v0p1"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "App_v0p1:8"};
	this.sidHashMap["App_v0p1:8"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S2>"] = {sid: "App_v0p1:11"};
	this.sidHashMap["App_v0p1:11"] = {rtwname: "<S2>"};
	this.rtwnameHashMap["<S3>"] = {sid: "App_v0p1:13"};
	this.sidHashMap["App_v0p1:13"] = {rtwname: "<S3>"};
	this.rtwnameHashMap["<Root>/Data Display"] = {sid: "App_v0p1:8"};
	this.sidHashMap["App_v0p1:8"] = {rtwname: "<Root>/Data Display"};
	this.rtwnameHashMap["<Root>/Data Display1"] = {sid: "App_v0p1:11"};
	this.sidHashMap["App_v0p1:11"] = {rtwname: "<Root>/Data Display1"};
	this.rtwnameHashMap["<Root>/Data Display2"] = {sid: "App_v0p1:13"};
	this.sidHashMap["App_v0p1:13"] = {rtwname: "<Root>/Data Display2"};
	this.rtwnameHashMap["<Root>/ThingSpeak Humidity"] = {sid: "App_v0p1:14"};
	this.sidHashMap["App_v0p1:14"] = {rtwname: "<Root>/ThingSpeak Humidity"};
	this.rtwnameHashMap["<Root>/ThingSpeak Read Temprature"] = {sid: "App_v0p1:6"};
	this.sidHashMap["App_v0p1:6"] = {rtwname: "<Root>/ThingSpeak Read Temprature"};
	this.rtwnameHashMap["<Root>/ThingSpeak water level"] = {sid: "App_v0p1:12"};
	this.sidHashMap["App_v0p1:12"] = {rtwname: "<Root>/ThingSpeak water level"};
	this.rtwnameHashMap["<S1>/In1"] = {sid: "App_v0p1:8:388"};
	this.sidHashMap["App_v0p1:8:388"] = {rtwname: "<S1>/In1"};
	this.rtwnameHashMap["<S1>/DataDisplay"] = {sid: "App_v0p1:8:386"};
	this.sidHashMap["App_v0p1:8:386"] = {rtwname: "<S1>/DataDisplay"};
	this.rtwnameHashMap["<S2>/In1"] = {sid: "App_v0p1:11:388"};
	this.sidHashMap["App_v0p1:11:388"] = {rtwname: "<S2>/In1"};
	this.rtwnameHashMap["<S2>/DataDisplay"] = {sid: "App_v0p1:11:386"};
	this.sidHashMap["App_v0p1:11:386"] = {rtwname: "<S2>/DataDisplay"};
	this.rtwnameHashMap["<S3>/In1"] = {sid: "App_v0p1:13:388"};
	this.sidHashMap["App_v0p1:13:388"] = {rtwname: "<S3>/In1"};
	this.rtwnameHashMap["<S3>/DataDisplay"] = {sid: "App_v0p1:13:386"};
	this.sidHashMap["App_v0p1:13:386"] = {rtwname: "<S3>/DataDisplay"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
