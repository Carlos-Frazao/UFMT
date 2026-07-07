import { UnauthorizedException } from '@nestjs/common';
import { JwtService } from '@nestjs/jwt';
import * as bcrypt from 'bcryptjs';
import { UsuarioService } from '../usuario/usuario.service';
import { AuthService } from './auth.service';

describe('AuthService', () => {
  let service: AuthService;
  let usuarioService: jest.Mocked<UsuarioService>;
  let jwtService: jest.Mocked<JwtService>;

  beforeEach(() => {
    usuarioService = {
      create: jest.fn(),
      findByEmail: jest.fn(),
    } as unknown as jest.Mocked<UsuarioService>;

    jwtService = {
      signAsync: jest.fn(),
    } as unknown as jest.Mocked<JwtService>;

    service = new AuthService(usuarioService, jwtService);
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

    await expect(service.login('admin@email.com', 'errada')).rejects.toBeInstanceOf(
      UnauthorizedException,
    );
  });
});
