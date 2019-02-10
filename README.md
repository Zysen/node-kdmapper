# node_kdmapper
NodeJS wrapper for kdmapper. kdmapper exploits vulnerabilities in intels iqvw64e.sys driver to allow driver manual mapping and memory reading and writing from kernel.

Example:

require("kdmapper").mapDriver(__dirname+"\\dummy.sys");