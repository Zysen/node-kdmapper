if (require('os').platform() !== 'win32') {
	console.error("This module only supports windows.");
	process.exit();
}
var kd = (require("fs").existsSync(__dirname+"/build/Release/kdmapper.node"))?require(__dirname+"/build/Release/kdmapper.node"):require(__dirname+'/bin/'+process.arch+'/kdmapper');
module.exports = kd;