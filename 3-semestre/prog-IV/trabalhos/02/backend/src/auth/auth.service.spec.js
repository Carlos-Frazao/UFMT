"use strict";
var __createBinding = (this && this.__createBinding) || (Object.create ? (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    var desc = Object.getOwnPropertyDescriptor(m, k);
    if (!desc || ("get" in desc ? !m.__esModule : desc.writable || desc.configurable)) {
      desc = { enumerable: true, get: function() { return m[k]; } };
    }
    Object.defineProperty(o, k2, desc);
}) : (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    o[k2] = m[k];
}));
var __setModuleDefault = (this && this.__setModuleDefault) || (Object.create ? (function(o, v) {
    Object.defineProperty(o, "default", { enumerable: true, value: v });
}) : function(o, v) {
    o["default"] = v;
});
var __importStar = (this && this.__importStar) || (function () {
    var ownKeys = function(o) {
        ownKeys = Object.getOwnPropertyNames || function (o) {
            var ar = [];
            for (var k in o) if (Object.prototype.hasOwnProperty.call(o, k)) ar[ar.length] = k;
            return ar;
        };
        return ownKeys(o);
    };
    return function (mod) {
        if (mod && mod.__esModule) return mod;
        var result = {};
        if (mod != null) for (var k = ownKeys(mod), i = 0; i < k.length; i++) if (k[i] !== "default") __createBinding(result, mod, k[i]);
        __setModuleDefault(result, mod);
        return result;
    };
})();
Object.defineProperty(exports, "__esModule", { value: true });
const common_1 = require("@nestjs/common");
const bcrypt = __importStar(require("bcryptjs"));
const auth_service_1 = require("./auth.service");
describe('AuthService', () => {
    let service;
    let usuarioService;
    let jwtService;
    beforeEach(() => {
        usuarioService = {
            create: jest.fn(),
            findByEmail: jest.fn(),
        };
        jwtService = {
            signAsync: jest.fn(),
        };
        service = new auth_service_1.AuthService(usuarioService, jwtService);
    });
    it('deve retornar access_token quando as credenciais forem validas', async () => {
        const senhaHash = await bcrypt.hash('123456', 10);
        usuarioService.findByEmail.mockResolvedValue({
            id: 1,
            email: 'admin@email.com',
            senha: senhaHash,
        });
        jwtService.signAsync.mockResolvedValue('token-jwt');
        await expect(service.login('admin@email.com', '123456')).resolves.toEqual({
            access_token: 'token-jwt',
        });
    });
    it('deve bloquear login com senha incorreta', async () => {
        const senhaHash = await bcrypt.hash('123456', 10);
        usuarioService.findByEmail.mockResolvedValue({
            id: 1,
            email: 'admin@email.com',
            senha: senhaHash,
        });
        await expect(service.login('admin@email.com', 'errada')).rejects.toBeInstanceOf(common_1.UnauthorizedException);
    });
});
//# sourceMappingURL=auth.service.spec.js.map