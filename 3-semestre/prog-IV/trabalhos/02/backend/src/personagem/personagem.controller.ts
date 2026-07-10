import {
  Body,
  Controller,
  Delete,
  Get,
  Param,
  Patch,
  Post,
  UseGuards,
} from '@nestjs/common';
import { JwtAuthGuard } from '../auth/jwt-auth.guard';
import { CreatePersonagemDto } from './dto/create-personagem.dto';
import { UpdatePersonagemDto } from './dto/update-personagem.dto';
import { PersonagemService } from './personagem.service';

@UseGuards(JwtAuthGuard)
@Controller('personagens')
export class PersonagemController {
  constructor(private readonly personagemService: PersonagemService) {}

  @Post()
  create(@Body() createPersonagemDto: CreatePersonagemDto) {
    console.log(`[API] POST /personagens | Payload: ${JSON.stringify(createPersonagemDto)}`);
    return this.personagemService.create(createPersonagemDto);
  }

  @Get()
  findAll() {
    console.log(`[API] GET /personagens  | Status: 200 OK | Fetching records...`);
    return this.personagemService.findAll();
  }

  @Delete(':id')
  remove(@Param('id') id: string) {
    console.log(`[API] DELETE /personagens/${id} | Target ID: ${id}`);
    return this.personagemService.remove(Number(id));
  }
}
// A professora pediu para o terminal cuspir as requisições que o front-end está fazendo para o back-end
//  então eu adicionei esses console.log() em cada rota.